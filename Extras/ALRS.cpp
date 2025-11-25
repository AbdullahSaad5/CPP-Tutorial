/*
 * =============================================================================
 * AUTOMATED LOGICAL REASONING SYSTEM (ALRS)
 * =============================================================================
 * 
 * A mini logic engine that allows users to:
 * - Input propositional variables and compound logical expressions
 * - Parse and evaluate logical expressions using standard operators
 * - Generate full truth tables with intermediate sub-expressions
 * - Validate multi-premise arguments using truth-table method
 * - Check logical equivalence between expressions
 * - Simulate reasoning chains (proof steps)
 * - Save results to .txt and .csv files
 * 
 * OPERATORS SUPPORTED:
 *   ! - NOT (unary negation)
 *   & - AND (conjunction)
 *   | - OR (disjunction)
 *   > - IMPLIES (implication: A > B means A → B)
 *   = - EQUIVALENT (biconditional: A = B means A ↔ B)
 * 
 * VARIABLES: Single uppercase letters (P, Q, R, S, T) - max 5 supported
 * 
 * Author: Student
 * Course: Discrete Structures
 * =============================================================================
 */

#include <iostream>  // For input/output operations (cin, cout)
#include <cstring>   // For string manipulation (strlen, strcpy, strcmp)
#include <cstdio>    // For file operations (FILE, fopen, fprintf, fclose)
#include <ctime>     // For timestamp generation

using namespace std;

// =============================================================================
// SECTION 1: CONSTANTS AND LIMITS
// =============================================================================
// These define the maximum sizes for our arrays since we're not using STL

const int MAX_EXPR_LEN = 256;      // Maximum length of an expression string
const int MAX_TOKENS = 100;        // Maximum number of tokens in an expression
const int MAX_TOKEN_LEN = 16;      // Maximum length of a single token
const int MAX_VARS = 5;            // Maximum number of unique variables (P,Q,R,S,T)
const int MAX_PREMISES = 5;        // Maximum number of premises for argument validation
const int MAX_SUBEXPR = 20;        // Maximum number of sub-expressions to track
const int MAX_ROWS = 32;           // Maximum truth table rows (2^5 = 32)

// =============================================================================
// SECTION 2: HELPER FUNCTIONS - Character and Token Identification
// =============================================================================

/*
 * isVariable - Check if a character is a valid propositional variable
 * Variables must be uppercase letters A-Z
 * 
 * @param c: The character to check
 * @return: true if c is an uppercase letter, false otherwise
 */
bool isVariable(char c) {
    return (c >= 'A' && c <= 'Z');
}

/*
 * isOperator - Check if a character is a valid logical operator
 * Valid operators: ! (NOT), & (AND), | (OR), > (IMPLIES), = (EQUIVALENT)
 * 
 * @param c: The character to check
 * @return: true if c is a valid operator, false otherwise
 */
bool isOperator(char c) {
    return (c == '!' || c == '&' || c == '|' || c == '>' || c == '=');
}

/*
 * isBinaryOperator - Check if operator requires two operands
 * All operators except NOT (!) are binary
 * 
 * @param c: The operator character
 * @return: true if binary operator, false if unary (!)
 */
bool isBinaryOperator(char c) {
    return (c == '&' || c == '|' || c == '>' || c == '=');
}

/*
 * isParenthesis - Check if character is a parenthesis
 * 
 * @param c: The character to check
 * @return: true if ( or ), false otherwise
 */
bool isParenthesis(char c) {
    return (c == '(' || c == ')');
}

/*
 * getPrecedence - Get the precedence level of an operator
 * Higher number = higher precedence (evaluated first)
 * 
 * Precedence levels (standard logic):
 *   ! (NOT)      = 5 (highest - evaluated first)
 *   & (AND)      = 4
 *   | (OR)       = 3
 *   > (IMPLIES)  = 2
 *   = (EQUIV)    = 1 (lowest - evaluated last)
 * 
 * @param op: The operator character
 * @return: Precedence level (1-5), or 0 if not an operator
 */
int getPrecedence(char op) {
    switch(op) {
        case '!': return 5;  // NOT has highest precedence
        case '&': return 4;  // AND
        case '|': return 3;  // OR
        case '>': return 2;  // IMPLIES
        case '=': return 1;  // EQUIVALENT has lowest precedence
        default:  return 0;  // Not an operator
    }
}

/*
 * isRightAssociative - Check if operator is right-associative
 * Only NOT (!) is right-associative (!!P means !(!P))
 * Binary operators are left-associative
 * 
 * @param op: The operator character
 * @return: true if right-associative, false if left-associative
 */
bool isRightAssociative(char op) {
    return (op == '!');  // Only NOT is right-associative
}

// =============================================================================
// SECTION 3: LOGICAL OPERATOR FUNCTIONS
// =============================================================================
// These functions implement the actual logic for each operator

/*
 * op_not - Logical NOT (negation)
 * Returns the opposite of the input
 * 
 * Truth table:
 *   A | !A
 *   T | F
 *   F | T
 * 
 * @param a: Input boolean value
 * @return: Negation of a
 */
bool op_not(bool a) {
    return !a;
}

/*
 * op_and - Logical AND (conjunction)
 * Returns true only if BOTH inputs are true
 * 
 * Truth table:
 *   A | B | A & B
 *   T | T |   T
 *   T | F |   F
 *   F | T |   F
 *   F | F |   F
 * 
 * @param a: First operand
 * @param b: Second operand
 * @return: a AND b
 */
bool op_and(bool a, bool b) {
    return a && b;
}

/*
 * op_or - Logical OR (disjunction)
 * Returns true if AT LEAST ONE input is true
 * 
 * Truth table:
 *   A | B | A | B
 *   T | T |   T
 *   T | F |   T
 *   F | T |   T
 *   F | F |   F
 * 
 * @param a: First operand
 * @param b: Second operand
 * @return: a OR b
 */
bool op_or(bool a, bool b) {
    return a || b;
}

/*
 * op_implies - Logical IMPLICATION (conditional)
 * A > B is equivalent to !A | B
 * "If A then B" - only false when A is true but B is false
 * 
 * Truth table:
 *   A | B | A > B
 *   T | T |   T
 *   T | F |   F   (only false case: true implies false)
 *   F | T |   T
 *   F | F |   T
 * 
 * @param a: Antecedent (the "if" part)
 * @param b: Consequent (the "then" part)
 * @return: a IMPLIES b
 */
bool op_implies(bool a, bool b) {
    return !a || b;  // Material implication: A→B ≡ ¬A∨B
}

/*
 * op_equiv - Logical EQUIVALENCE (biconditional)
 * A = B is true when both have the same truth value
 * "A if and only if B"
 * 
 * Truth table:
 *   A | B | A = B
 *   T | T |   T
 *   T | F |   F
 *   F | T |   F
 *   F | F |   T
 * 
 * @param a: First proposition
 * @param b: Second proposition
 * @return: a EQUIVALENT b
 */
bool op_equiv(bool a, bool b) {
    return a == b;  // True when both have same value
}

// =============================================================================
// SECTION 4: TOKENIZER
// =============================================================================
// Converts an input string into an array of tokens (variables, operators, parens)

/*
 * tokenize - Split an expression string into individual tokens
 * 
 * This function takes a raw expression like "(P&Q)>R" and breaks it into
 * individual tokens: "(", "P", "&", "Q", ")", ">", "R"
 * 
 * It also validates the input and reports errors for:
 * - Invalid characters
 * - Consecutive binary operators
 * - Unmatched parentheses
 * 
 * @param input: The raw expression string
 * @param tokens: 2D array to store the tokens (output)
 * @param errorMsg: Buffer to store error message if any (output)
 * @return: Number of tokens, or -1 if error
 */
int tokenize(const char* input, char tokens[][MAX_TOKEN_LEN], char* errorMsg) {
    int tokenCount = 0;           // Number of tokens found
    int parenBalance = 0;         // Track parenthesis balance
    int len = strlen(input);      // Length of input string
    char prevTokenType = ' ';     // Track previous token type for validation
    
    // Process each character in the input
    for (int i = 0; i < len; i++) {
        char c = input[i];
        
        // Skip whitespace
        if (c == ' ' || c == '\t' || c == '\n') {
            continue;
        }
        
        // Check for valid character
        if (!isVariable(c) && !isOperator(c) && !isParenthesis(c)) {
            sprintf(errorMsg, "Error: Invalid character '%c' at position %d", c, i);
            return -1;
        }
        
        // Handle variables (single uppercase letters)
        if (isVariable(c)) {
            // Check for consecutive variables without operator
            if (prevTokenType == 'V') {
                sprintf(errorMsg, "Error: Missing operator between variables at position %d", i);
                return -1;
            }
            tokens[tokenCount][0] = c;
            tokens[tokenCount][1] = '\0';
            tokenCount++;
            prevTokenType = 'V';  // V for Variable
        }
        // Handle operators
        else if (isOperator(c)) {
            // Check for consecutive binary operators (except ! which is unary)
            if (prevTokenType == 'O' && c != '!') {
                sprintf(errorMsg, "Error: Consecutive operators at position %d", i);
                return -1;
            }
            // Check for binary operator at start or after open paren
            if (isBinaryOperator(c) && (prevTokenType == ' ' || prevTokenType == '(')) {
                sprintf(errorMsg, "Error: Binary operator '%c' cannot start expression or follow '('", c);
                return -1;
            }
            tokens[tokenCount][0] = c;
            tokens[tokenCount][1] = '\0';
            tokenCount++;
            prevTokenType = 'O';  // O for Operator
        }
        // Handle parentheses
        else if (c == '(') {
            parenBalance++;
            tokens[tokenCount][0] = c;
            tokens[tokenCount][1] = '\0';
            tokenCount++;
            prevTokenType = '(';
        }
        else if (c == ')') {
            parenBalance--;
            if (parenBalance < 0) {
                sprintf(errorMsg, "Error: Unmatched closing parenthesis at position %d", i);
                return -1;
            }
            // Check for empty parentheses
            if (prevTokenType == '(') {
                sprintf(errorMsg, "Error: Empty parentheses at position %d", i);
                return -1;
            }
            // Check for operator before closing paren
            if (prevTokenType == 'O') {
                sprintf(errorMsg, "Error: Operator before closing parenthesis at position %d", i);
                return -1;
            }
            tokens[tokenCount][0] = c;
            tokens[tokenCount][1] = '\0';
            tokenCount++;
            prevTokenType = ')';
        }
        
        // Safety check for token overflow
        if (tokenCount >= MAX_TOKENS) {
            sprintf(errorMsg, "Error: Expression too long (max %d tokens)", MAX_TOKENS);
            return -1;
        }
    }
    
    // Check for unmatched opening parentheses
    if (parenBalance != 0) {
        sprintf(errorMsg, "Error: %d unmatched opening parenthesis(es)", parenBalance);
        return -1;
    }
    
    // Check for trailing operator
    if (tokenCount > 0 && prevTokenType == 'O') {
        sprintf(errorMsg, "Error: Expression cannot end with an operator");
        return -1;
    }
    
    // Check for empty expression
    if (tokenCount == 0) {
        sprintf(errorMsg, "Error: Empty expression");
        return -1;
    }
    
    return tokenCount;
}

// =============================================================================
// SECTION 5: INFIX TO POSTFIX CONVERSION (Shunting-Yard Algorithm)
// =============================================================================

/*
 * infixToPostfix - Convert infix notation to postfix (Reverse Polish Notation)
 * 
 * The Shunting-Yard Algorithm:
 * 1. Read tokens left to right
 * 2. If token is a variable, add to output
 * 3. If token is an operator:
 *    - While there's an operator on stack with greater precedence
 *      (or equal precedence and left-associative), pop to output
 *    - Push current operator to stack
 * 4. If token is '(', push to stack
 * 5. If token is ')', pop operators to output until '(' is found
 * 6. After all tokens, pop remaining operators to output
 * 
 * Example: (P & Q) > R
 * Infix tokens:  ( P & Q ) > R
 * Postfix:       P Q & R >
 * 
 * @param tokens: Array of input tokens (infix notation)
 * @param tokenCount: Number of tokens
 * @param postfix: Array to store output tokens (postfix notation)
 * @param errorMsg: Buffer for error message
 * @return: Number of postfix tokens, or -1 on error
 */
int infixToPostfix(char tokens[][MAX_TOKEN_LEN], int tokenCount, 
                   char postfix[][MAX_TOKEN_LEN], char* errorMsg) {
    
    // Operator stack (simulated with array)
    char opStack[MAX_TOKENS][MAX_TOKEN_LEN];
    int stackTop = -1;  // -1 means empty stack
    
    int postfixCount = 0;  // Number of tokens in output
    
    // Process each token
    for (int i = 0; i < tokenCount; i++) {
        char* token = tokens[i];
        char c = token[0];  // First character of token
        
        // Case 1: Token is a variable - add directly to output
        if (isVariable(c)) {
            strcpy(postfix[postfixCount], token);
            postfixCount++;
        }
        // Case 2: Token is an operator
        else if (isOperator(c)) {
            // Pop operators with higher or equal precedence (for left-associative)
            while (stackTop >= 0) {
                char topOp = opStack[stackTop][0];
                
                // Don't pop if top is a parenthesis
                if (topOp == '(') break;
                
                // Check precedence rules
                int currentPrec = getPrecedence(c);
                int stackPrec = getPrecedence(topOp);
                
                // Pop if: stack operator has higher precedence, OR
                // equal precedence and current operator is left-associative
                if (stackPrec > currentPrec || 
                    (stackPrec == currentPrec && !isRightAssociative(c))) {
                    strcpy(postfix[postfixCount], opStack[stackTop]);
                    postfixCount++;
                    stackTop--;
                } else {
                    break;
                }
            }
            
            // Push current operator to stack
            stackTop++;
            strcpy(opStack[stackTop], token);
        }
        // Case 3: Left parenthesis - push to stack
        else if (c == '(') {
            stackTop++;
            strcpy(opStack[stackTop], token);
        }
        // Case 4: Right parenthesis - pop until left paren found
        else if (c == ')') {
            // Pop operators until we find matching '('
            while (stackTop >= 0 && opStack[stackTop][0] != '(') {
                strcpy(postfix[postfixCount], opStack[stackTop]);
                postfixCount++;
                stackTop--;
            }
            
            // Pop the '(' but don't add to output
            if (stackTop >= 0) {
                stackTop--;
            } else {
                sprintf(errorMsg, "Error: Mismatched parentheses");
                return -1;
            }
        }
    }
    
    // Pop remaining operators from stack
    while (stackTop >= 0) {
        if (opStack[stackTop][0] == '(') {
            sprintf(errorMsg, "Error: Mismatched parentheses");
            return -1;
        }
        strcpy(postfix[postfixCount], opStack[stackTop]);
        postfixCount++;
        stackTop--;
    }
    
    return postfixCount;
}

// =============================================================================
// SECTION 6: VARIABLE EXTRACTION
// =============================================================================

/*
 * extractVariables - Find all unique variables in an expression
 * 
 * Scans through tokens and collects unique variable names.
 * Variables are stored in sorted order for consistent truth table generation.
 * 
 * @param tokens: Array of tokens from the expression
 * @param tokenCount: Number of tokens
 * @param vars: Output array to store unique variable characters
 * @return: Number of unique variables found
 */
int extractVariables(char tokens[][MAX_TOKEN_LEN], int tokenCount, char vars[]) {
    int varCount = 0;
    
    // Scan all tokens for variables
    for (int i = 0; i < tokenCount; i++) {
        char c = tokens[i][0];
        
        if (isVariable(c)) {
            // Check if variable already in list
            bool found = false;
            for (int j = 0; j < varCount; j++) {
                if (vars[j] == c) {
                    found = true;
                    break;
                }
            }
            
            // Add new variable
            if (!found && varCount < MAX_VARS) {
                vars[varCount] = c;
                varCount++;
            }
        }
    }
    
    // Sort variables alphabetically using simple bubble sort
    for (int i = 0; i < varCount - 1; i++) {
        for (int j = 0; j < varCount - i - 1; j++) {
            if (vars[j] > vars[j + 1]) {
                char temp = vars[j];
                vars[j] = vars[j + 1];
                vars[j + 1] = temp;
            }
        }
    }
    
    vars[varCount] = '\0';  // Null-terminate
    return varCount;
}

/*
 * extractVariablesFromMultiple - Extract variables from multiple expressions
 * 
 * Used when we have multiple premises and need to find all variables
 * across all expressions.
 * 
 * @param expressions: Array of expression strings
 * @param exprCount: Number of expressions
 * @param vars: Output array for variables
 * @return: Number of unique variables
 */
int extractVariablesFromMultiple(char expressions[][MAX_EXPR_LEN], int exprCount, char vars[]) {
    int varCount = 0;
    char tempTokens[MAX_TOKENS][MAX_TOKEN_LEN];
    char errorMsg[MAX_EXPR_LEN];
    
    for (int e = 0; e < exprCount; e++) {
        int tokenCount = tokenize(expressions[e], tempTokens, errorMsg);
        if (tokenCount < 0) continue;
        
        for (int i = 0; i < tokenCount; i++) {
            char c = tempTokens[i][0];
            if (isVariable(c)) {
                bool found = false;
                for (int j = 0; j < varCount; j++) {
                    if (vars[j] == c) {
                        found = true;
                        break;
                    }
                }
                if (!found && varCount < MAX_VARS) {
                    vars[varCount] = c;
                    varCount++;
                }
            }
        }
    }
    
    // Sort variables
    for (int i = 0; i < varCount - 1; i++) {
        for (int j = 0; j < varCount - i - 1; j++) {
            if (vars[j] > vars[j + 1]) {
                char temp = vars[j];
                vars[j] = vars[j + 1];
                vars[j + 1] = temp;
            }
        }
    }
    
    vars[varCount] = '\0';
    return varCount;
}

// =============================================================================
// SECTION 7: POSTFIX EXPRESSION EVALUATOR
// =============================================================================

/*
 * evaluatePostfix - Evaluate a postfix expression with given variable values
 * 
 * Uses a stack to evaluate:
 * 1. If token is a variable, push its value
 * 2. If token is unary operator (!), pop one value, apply, push result
 * 3. If token is binary operator, pop two values, apply, push result
 * 4. Final value on stack is the result
 * 
 * Example: P Q & (postfix for P & Q)
 * If P=1, Q=0:
 * - Push 1 (for P)
 * - Push 0 (for Q)
 * - Pop 0, pop 1, compute 1 & 0 = 0, push 0
 * - Result: 0
 * 
 * @param postfix: Array of postfix tokens
 * @param postfixLen: Number of tokens
 * @param vars: Array of variable names
 * @param values: Array of variable values (0 or 1)
 * @param varCount: Number of variables
 * @return: Evaluated result (true/false)
 */
bool evaluatePostfix(char postfix[][MAX_TOKEN_LEN], int postfixLen,
                     char vars[], int values[], int varCount) {
    
    // Evaluation stack
    bool stack[MAX_TOKENS];
    int stackTop = -1;
    
    // Process each token in postfix expression
    for (int i = 0; i < postfixLen; i++) {
        char c = postfix[i][0];
        
        // If variable, find its value and push
        if (isVariable(c)) {
            // Find the variable in our list
            for (int j = 0; j < varCount; j++) {
                if (vars[j] == c) {
                    stackTop++;
                    stack[stackTop] = (values[j] == 1);
                    break;
                }
            }
        }
        // If NOT operator (unary)
        else if (c == '!') {
            if (stackTop >= 0) {
                bool a = stack[stackTop];
                stack[stackTop] = op_not(a);  // Replace top with negation
            }
        }
        // If binary operator
        else if (isBinaryOperator(c)) {
            if (stackTop >= 1) {
                bool b = stack[stackTop]; stackTop--;  // Pop second operand
                bool a = stack[stackTop];              // Pop first operand
                
                bool result = false;
                switch(c) {
                    case '&': result = op_and(a, b); break;
                    case '|': result = op_or(a, b); break;
                    case '>': result = op_implies(a, b); break;
                    case '=': result = op_equiv(a, b); break;
                }
                
                stack[stackTop] = result;  // Push result
            }
        }
    }
    
    // Return the final result (should be only item on stack)
    return (stackTop >= 0) ? stack[stackTop] : false;
}

// =============================================================================
// SECTION 8: EXPRESSION STRING BUILDER (for sub-expressions)
// =============================================================================

/*
 * buildExpressionString - Convert tokens back to a readable string
 * 
 * @param tokens: Array of tokens
 * @param count: Number of tokens
 * @param output: Output string buffer
 */
void buildExpressionString(char tokens[][MAX_TOKEN_LEN], int count, char* output) {
    output[0] = '\0';
    for (int i = 0; i < count; i++) {
        strcat(output, tokens[i]);
    }
}

// =============================================================================
// SECTION 9: TRUTH TABLE GENERATOR
// =============================================================================

/*
 * generateTruthTable - Generate and display a complete truth table
 * 
 * Creates a truth table with 2^n rows where n is the number of variables.
 * Uses binary counting to generate all possible combinations of truth values.
 * 
 * For n variables, we count from 0 to 2^n - 1:
 * - Row 0: all variables false (000...0)
 * - Row 1: last variable true  (000...1)
 * - Row 2^n - 1: all true      (111...1)
 * 
 * @param expression: The original expression string
 * @param showIntermediate: Whether to show sub-expression columns
 * @param resultTable: 2D array to store results for file saving
 * @param resultRowCount: Pointer to store number of rows
 */
void generateTruthTable(const char* expression, bool showIntermediate,
                        int resultTable[][MAX_VARS + MAX_SUBEXPR + 1], 
                        int* resultRowCount) {
    
    char tokens[MAX_TOKENS][MAX_TOKEN_LEN];
    char postfix[MAX_TOKENS][MAX_TOKEN_LEN];
    char errorMsg[MAX_EXPR_LEN];
    char vars[MAX_VARS + 1];
    
    // Step 1: Tokenize the expression
    int tokenCount = tokenize(expression, tokens, errorMsg);
    if (tokenCount < 0) {
        cout << errorMsg << endl;
        *resultRowCount = 0;
        return;
    }
    
    // Step 2: Extract variables
    int varCount = extractVariables(tokens, tokenCount, vars);
    if (varCount == 0) {
        cout << "Error: No variables found in expression" << endl;
        *resultRowCount = 0;
        return;
    }
    if (varCount > MAX_VARS) {
        cout << "Error: Maximum of " << MAX_VARS << " propositional variables supported" << endl;
        *resultRowCount = 0;
        return;
    }
    
    // Step 3: Convert to postfix
    int postfixLen = infixToPostfix(tokens, tokenCount, postfix, errorMsg);
    if (postfixLen < 0) {
        cout << errorMsg << endl;
        *resultRowCount = 0;
        return;
    }
    
    // Calculate number of rows (2^n)
    int numRows = 1;
    for (int i = 0; i < varCount; i++) {
        numRows *= 2;
    }
    
    // Print header
    cout << "\n";
    cout << "Truth Table for: " << expression << endl;
    cout << "Variables: ";
    for (int i = 0; i < varCount; i++) {
        cout << vars[i];
        if (i < varCount - 1) cout << ", ";
    }
    cout << endl;
    cout << string(60, '-') << endl;
    
    // Print column headers
    for (int i = 0; i < varCount; i++) {
        cout << " " << vars[i] << " |";
    }
    cout << " " << expression << endl;
    cout << string(60, '-') << endl;
    
    // Generate each row
    *resultRowCount = numRows;
    
    for (int row = 0; row < numRows; row++) {
        int values[MAX_VARS];
        
        // Generate truth values using binary representation
        // For row number, bit i represents variable varCount-1-i
        for (int i = 0; i < varCount; i++) {
            // Extract bit for this variable
            // We want first variable to change slowest, last to change fastest
            int bitPosition = varCount - 1 - i;
            values[i] = (row >> bitPosition) & 1;
            
            // Store in result table
            resultTable[row][i] = values[i];
            
            // Print value
            cout << " " << values[i] << " |";
        }
        
        // Evaluate expression
        bool result = evaluatePostfix(postfix, postfixLen, vars, values, varCount);
        resultTable[row][varCount] = result ? 1 : 0;
        
        cout << "    " << (result ? "T" : "F") << endl;
    }
    
    cout << string(60, '-') << endl;
}

// =============================================================================
// SECTION 10: ARGUMENT VALIDATOR
// =============================================================================

/*
 * validateArgument - Check if a logical argument is valid
 * 
 * An argument is VALID if: whenever ALL premises are true, 
 * the conclusion MUST also be true.
 * 
 * An argument is INVALID if: there exists ANY row where all premises
 * are true but the conclusion is false (this is a counterexample).
 * 
 * Method:
 * 1. Generate all possible truth value combinations
 * 2. For each combination, evaluate all premises and conclusion
 * 3. Find rows where all premises are true
 * 4. Check if conclusion is also true in those rows
 * 
 * @param premises: Array of premise expression strings
 * @param premiseCount: Number of premises
 * @param conclusion: The conclusion expression string
 * @param counterexample: Buffer to store counterexample if found
 * @return: true if argument is valid, false if invalid
 */
bool validateArgument(char premises[][MAX_EXPR_LEN], int premiseCount,
                      const char* conclusion, char* counterexample) {
    
    char tokens[MAX_TOKENS][MAX_TOKEN_LEN];
    char postfix[MAX_TOKENS][MAX_TOKEN_LEN];
    char errorMsg[MAX_EXPR_LEN];
    char vars[MAX_VARS + 1];
    
    // Arrays to store parsed premises and conclusion
    char premisePostfix[MAX_PREMISES][MAX_TOKENS][MAX_TOKEN_LEN];
    int premisePostfixLen[MAX_PREMISES];
    char conclusionPostfix[MAX_TOKENS][MAX_TOKEN_LEN];
    int conclusionPostfixLen;
    
    // Step 1: Collect all expressions (premises + conclusion)
    char allExpressions[MAX_PREMISES + 1][MAX_EXPR_LEN];
    for (int i = 0; i < premiseCount; i++) {
        strcpy(allExpressions[i], premises[i]);
    }
    strcpy(allExpressions[premiseCount], conclusion);
    
    // Step 2: Extract all variables
    int varCount = extractVariablesFromMultiple(allExpressions, premiseCount + 1, vars);
    if (varCount == 0 || varCount > MAX_VARS) {
        strcpy(counterexample, "Error with variables");
        return false;
    }
    
    // Step 3: Parse all premises
    for (int p = 0; p < premiseCount; p++) {
        int tokenCount = tokenize(premises[p], tokens, errorMsg);
        if (tokenCount < 0) {
            cout << "Error in premise " << (p + 1) << ": " << errorMsg << endl;
            return false;
        }
        
        premisePostfixLen[p] = infixToPostfix(tokens, tokenCount, premisePostfix[p], errorMsg);
        if (premisePostfixLen[p] < 0) {
            cout << "Error parsing premise " << (p + 1) << ": " << errorMsg << endl;
            return false;
        }
    }
    
    // Step 4: Parse conclusion
    int tokenCount = tokenize(conclusion, tokens, errorMsg);
    if (tokenCount < 0) {
        cout << "Error in conclusion: " << errorMsg << endl;
        return false;
    }
    conclusionPostfixLen = infixToPostfix(tokens, tokenCount, conclusionPostfix, errorMsg);
    if (conclusionPostfixLen < 0) {
        cout << "Error parsing conclusion: " << errorMsg << endl;
        return false;
    }
    
    // Step 5: Test all truth value combinations
    int numRows = 1;
    for (int i = 0; i < varCount; i++) {
        numRows *= 2;
    }
    
    cout << "\nAnalyzing argument validity...\n" << endl;
    
    // Print header
    cout << "Truth Table:\n";
    cout << string(80, '-') << endl;
    
    // Column headers
    for (int i = 0; i < varCount; i++) {
        cout << vars[i] << " | ";
    }
    for (int p = 0; p < premiseCount; p++) {
        cout << "P" << (p + 1) << " | ";
    }
    cout << "Conc | Result" << endl;
    cout << string(80, '-') << endl;
    
    bool isValid = true;
    counterexample[0] = '\0';
    
    for (int row = 0; row < numRows; row++) {
        int values[MAX_VARS];
        
        // Generate truth values
        for (int i = 0; i < varCount; i++) {
            int bitPosition = varCount - 1 - i;
            values[i] = (row >> bitPosition) & 1;
            cout << values[i] << " | ";
        }
        
        // Evaluate all premises
        bool allPremisesTrue = true;
        for (int p = 0; p < premiseCount; p++) {
            bool premiseResult = evaluatePostfix(premisePostfix[p], premisePostfixLen[p],
                                                  vars, values, varCount);
            cout << (premiseResult ? "T" : "F") << "  | ";
            if (!premiseResult) {
                allPremisesTrue = false;
            }
        }
        
        // Evaluate conclusion
        bool conclusionResult = evaluatePostfix(conclusionPostfix, conclusionPostfixLen,
                                                 vars, values, varCount);
        cout << (conclusionResult ? "T" : "F") << "    | ";
        
        // Check validity
        if (allPremisesTrue) {
            if (conclusionResult) {
                cout << "VALID";
            } else {
                cout << "INVALID";
                isValid = false;
                
                // Record counterexample
                if (strlen(counterexample) == 0) {
                    char temp[MAX_EXPR_LEN];
                    strcpy(counterexample, "Counterexample: ");
                    for (int i = 0; i < varCount; i++) {
                        sprintf(temp, "%c=%s", vars[i], values[i] ? "T" : "F");
                        strcat(counterexample, temp);
                        if (i < varCount - 1) strcat(counterexample, ", ");
                    }
                }
            }
        } else {
            cout << "-";  // Premises not all true, row doesn't test validity
        }
        cout << endl;
    }
    
    cout << string(80, '-') << endl;
    
    return isValid;
}

// =============================================================================
// SECTION 11: LOGICAL EQUIVALENCE CHECKER
// =============================================================================

/*
 * checkEquivalence - Check if two expressions are logically equivalent
 * 
 * Two expressions are logically equivalent if they have the same truth
 * value for ALL possible combinations of variable values.
 * 
 * @param expr1: First expression
 * @param expr2: Second expression
 * @param differences: Buffer to store rows where expressions differ
 * @return: true if equivalent, false otherwise
 */
bool checkEquivalence(const char* expr1, const char* expr2, char* differences) {
    char tokens1[MAX_TOKENS][MAX_TOKEN_LEN], tokens2[MAX_TOKENS][MAX_TOKEN_LEN];
    char postfix1[MAX_TOKENS][MAX_TOKEN_LEN], postfix2[MAX_TOKENS][MAX_TOKEN_LEN];
    char errorMsg[MAX_EXPR_LEN];
    char vars[MAX_VARS + 1];
    
    // Tokenize both expressions
    int tokenCount1 = tokenize(expr1, tokens1, errorMsg);
    if (tokenCount1 < 0) {
        cout << "Error in expression 1: " << errorMsg << endl;
        return false;
    }
    
    int tokenCount2 = tokenize(expr2, tokens2, errorMsg);
    if (tokenCount2 < 0) {
        cout << "Error in expression 2: " << errorMsg << endl;
        return false;
    }
    
    // Collect all variables from both expressions
    char allExprs[2][MAX_EXPR_LEN];
    strcpy(allExprs[0], expr1);
    strcpy(allExprs[1], expr2);
    int varCount = extractVariablesFromMultiple(allExprs, 2, vars);
    
    if (varCount == 0 || varCount > MAX_VARS) {
        cout << "Error: Invalid number of variables" << endl;
        return false;
    }
    
    // Convert to postfix
    int postfixLen1 = infixToPostfix(tokens1, tokenCount1, postfix1, errorMsg);
    if (postfixLen1 < 0) {
        cout << "Error: " << errorMsg << endl;
        return false;
    }
    
    int postfixLen2 = infixToPostfix(tokens2, tokenCount2, postfix2, errorMsg);
    if (postfixLen2 < 0) {
        cout << "Error: " << errorMsg << endl;
        return false;
    }
    
    // Calculate number of rows
    int numRows = 1;
    for (int i = 0; i < varCount; i++) {
        numRows *= 2;
    }
    
    // Print header
    cout << "\nEquivalence Check:" << endl;
    cout << "Expression 1: " << expr1 << endl;
    cout << "Expression 2: " << expr2 << endl;
    cout << string(70, '-') << endl;
    
    // Column headers
    for (int i = 0; i < varCount; i++) {
        cout << vars[i] << " | ";
    }
    cout << "Expr1 | Expr2 | Match" << endl;
    cout << string(70, '-') << endl;
    
    bool isEquivalent = true;
    differences[0] = '\0';
    int diffCount = 0;
    
    for (int row = 0; row < numRows; row++) {
        int values[MAX_VARS];
        
        // Generate truth values
        for (int i = 0; i < varCount; i++) {
            int bitPosition = varCount - 1 - i;
            values[i] = (row >> bitPosition) & 1;
            cout << values[i] << " | ";
        }
        
        // Evaluate both expressions
        bool result1 = evaluatePostfix(postfix1, postfixLen1, vars, values, varCount);
        bool result2 = evaluatePostfix(postfix2, postfixLen2, vars, values, varCount);
        
        cout << "  " << (result1 ? "T" : "F") << "   |   " 
             << (result2 ? "T" : "F") << "   | ";
        
        if (result1 == result2) {
            cout << "Yes" << endl;
        } else {
            cout << "NO <--" << endl;
            isEquivalent = false;
            diffCount++;
            
            // Record difference
            if (diffCount <= 3) {  // Only record first 3 differences
                char temp[MAX_EXPR_LEN];
                sprintf(temp, "Row %d: ", row + 1);
                strcat(differences, temp);
                for (int i = 0; i < varCount; i++) {
                    sprintf(temp, "%c=%d ", vars[i], values[i]);
                    strcat(differences, temp);
                }
                strcat(differences, "\n");
            }
        }
    }
    
    cout << string(70, '-') << endl;
    
    return isEquivalent;
}

// =============================================================================
// SECTION 12: REASONING CHAIN / PROOF SIMULATOR
// =============================================================================

/*
 * buildImplicationMatrix - Build a matrix representing implications between variables
 * 
 * For simple implications of the form "X > Y", we record that X implies Y
 * in a matrix. This is used for the reasoning chain simulator.
 * 
 * @param premises: Array of premise strings
 * @param premiseCount: Number of premises
 * @param vars: Array of variable names
 * @param varCount: Number of variables
 * @param matrix: 2D array to store implications (matrix[i][j] = 1 means vars[i] > vars[j])
 */
void buildImplicationMatrix(char premises[][MAX_EXPR_LEN], int premiseCount,
                            char vars[], int varCount, int matrix[][MAX_VARS]) {
    
    // Initialize matrix to 0
    for (int i = 0; i < varCount; i++) {
        for (int j = 0; j < varCount; j++) {
            matrix[i][j] = 0;
        }
    }
    
    // Parse each premise looking for simple implications (X > Y)
    for (int p = 0; p < premiseCount; p++) {
        char* premise = premises[p];
        int len = strlen(premise);
        
        // Look for pattern: VAR > VAR (possibly with spaces)
        char var1 = '\0', var2 = '\0';
        bool foundImplies = false;
        
        for (int i = 0; i < len; i++) {
            if (isVariable(premise[i])) {
                if (!foundImplies) {
                    var1 = premise[i];
                } else {
                    var2 = premise[i];
                }
            } else if (premise[i] == '>') {
                foundImplies = true;
            }
        }
        
        // If we found a simple implication X > Y
        if (var1 != '\0' && var2 != '\0' && foundImplies) {
            // Find indices in vars array
            int idx1 = -1, idx2 = -1;
            for (int i = 0; i < varCount; i++) {
                if (vars[i] == var1) idx1 = i;
                if (vars[i] == var2) idx2 = i;
            }
            
            if (idx1 >= 0 && idx2 >= 0) {
                matrix[idx1][idx2] = 1;
            }
        }
    }
}

/*
 * deriveTransitiveClosure - Apply transitive closure to find all derived implications
 * 
 * Uses the Warshall algorithm:
 * If A > B and B > C, then we can derive A > C
 * 
 * @param matrix: Implication matrix (modified in place)
 * @param varCount: Number of variables
 * @param derivations: Buffer to store derivation steps
 */
void deriveTransitiveClosure(int matrix[][MAX_VARS], int varCount, 
                             char vars[], char* derivations) {
    
    derivations[0] = '\0';
    char temp[256];
    int stepCount = 0;
    
    // Warshall's algorithm for transitive closure
    for (int k = 0; k < varCount; k++) {
        for (int i = 0; i < varCount; i++) {
            for (int j = 0; j < varCount; j++) {
                // If i > k and k > j, then we can derive i > j
                if (matrix[i][k] && matrix[k][j] && !matrix[i][j] && i != j) {
                    matrix[i][j] = 1;
                    stepCount++;
                    
                    sprintf(temp, "Step %d: From %c > %c and %c > %c, derive %c > %c (Hypothetical Syllogism)\n",
                            stepCount, vars[i], vars[k], vars[k], vars[j], vars[i], vars[j]);
                    strcat(derivations, temp);
                }
            }
        }
    }
    
    if (stepCount == 0) {
        strcpy(derivations, "No new implications could be derived.\n");
    }
}

/*
 * simulateReasoningChain - Run the reasoning chain simulator
 * 
 * Takes a set of premises (implications) and derives new conclusions
 * using inference rules like hypothetical syllogism and modus ponens.
 * 
 * @param premises: Array of premise strings
 * @param premiseCount: Number of premises
 * @param targetConclusion: Optional target conclusion to check for
 */
void simulateReasoningChain(char premises[][MAX_EXPR_LEN], int premiseCount,
                            const char* targetConclusion) {
    
    char vars[MAX_VARS + 1];
    int varCount = extractVariablesFromMultiple(premises, premiseCount, vars);
    
    if (varCount == 0) {
        cout << "Error: No variables found in premises" << endl;
        return;
    }
    
    cout << "\n=== Reasoning Chain Simulator ===" << endl;
    cout << "\nGiven Premises:" << endl;
    for (int i = 0; i < premiseCount; i++) {
        cout << "  " << (i + 1) << ". " << premises[i] << endl;
    }
    
    cout << "\nVariables detected: ";
    for (int i = 0; i < varCount; i++) {
        cout << vars[i];
        if (i < varCount - 1) cout << ", ";
    }
    cout << endl;
    
    // Build and display implication matrix
    int matrix[MAX_VARS][MAX_VARS];
    buildImplicationMatrix(premises, premiseCount, vars, varCount, matrix);
    
    cout << "\nImplication Matrix (before derivation):" << endl;
    cout << "  ";
    for (int j = 0; j < varCount; j++) cout << vars[j] << " ";
    cout << endl;
    for (int i = 0; i < varCount; i++) {
        cout << vars[i] << " ";
        for (int j = 0; j < varCount; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Derive new implications
    char derivations[2048];
    cout << "\nApplying inference rules..." << endl;
    cout << string(40, '-') << endl;
    
    deriveTransitiveClosure(matrix, varCount, vars, derivations);
    cout << derivations;
    
    cout << string(40, '-') << endl;
    
    // Display final implications
    cout << "\nAll derived implications:" << endl;
    bool foundAny = false;
    for (int i = 0; i < varCount; i++) {
        for (int j = 0; j < varCount; j++) {
            if (matrix[i][j]) {
                cout << "  " << vars[i] << " > " << vars[j] << endl;
                foundAny = true;
            }
        }
    }
    if (!foundAny) {
        cout << "  (none)" << endl;
    }
    
    // Check target conclusion if provided
    if (targetConclusion != NULL && strlen(targetConclusion) > 0) {
        cout << "\nChecking target conclusion: " << targetConclusion << endl;
        
        // Simple check for X > Y pattern
        char var1 = '\0', var2 = '\0';
        bool foundImplies = false;
        int len = strlen(targetConclusion);
        
        for (int i = 0; i < len; i++) {
            if (isVariable(targetConclusion[i])) {
                if (!foundImplies) var1 = targetConclusion[i];
                else var2 = targetConclusion[i];
            } else if (targetConclusion[i] == '>') {
                foundImplies = true;
            }
        }
        
        if (var1 && var2) {
            int idx1 = -1, idx2 = -1;
            for (int i = 0; i < varCount; i++) {
                if (vars[i] == var1) idx1 = i;
                if (vars[i] == var2) idx2 = i;
            }
            
            if (idx1 >= 0 && idx2 >= 0 && matrix[idx1][idx2]) {
                cout << "Target conclusion " << var1 << " > " << var2 << " can be derived!" << endl;
            } else {
                cout << "Target conclusion cannot be derived from the given premises." << endl;
            }
        }
    }
}

// =============================================================================
// SECTION 13: FILE HANDLING
// =============================================================================

/*
 * getCurrentTimestamp - Get current date/time as a string
 * 
 * @param buffer: Buffer to store the timestamp string
 */
void getCurrentTimestamp(char* buffer) {
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    strftime(buffer, 64, "%Y-%m-%d %H:%M:%S", timeinfo);
}

/*
 * saveResultsToTxt - Save results to a human-readable text file
 * 
 * @param filename: Name of the file to save
 * @param expression: The expression being analyzed
 * @param vars: Variable names
 * @param varCount: Number of variables
 * @param resultTable: Truth table results
 * @param rowCount: Number of rows
 * @param verdict: Final verdict string
 * @param counterexample: Counterexample if any
 */
void saveResultsToTxt(const char* filename, const char* expression,
                      char vars[], int varCount,
                      int resultTable[][MAX_VARS + MAX_SUBEXPR + 1],
                      int rowCount, const char* verdict, const char* counterexample) {
    
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        cout << "Error: Could not open file " << filename << " for writing" << endl;
        return;
    }
    
    char timestamp[64];
    getCurrentTimestamp(timestamp);
    
    // Write header
    fprintf(file, "ALRS Output\n");
    fprintf(file, "Timestamp: %s\n", timestamp);
    fprintf(file, "Variables: ");
    for (int i = 0; i < varCount; i++) {
        fprintf(file, "%c", vars[i]);
        if (i < varCount - 1) fprintf(file, " ");
    }
    fprintf(file, "\n");
    fprintf(file, "Expression: %s\n", expression);
    fprintf(file, "---------------------------------\n");
    
    // Write column headers
    for (int i = 0; i < varCount; i++) {
        fprintf(file, "%c ", vars[i]);
    }
    fprintf(file, "| %s\n", expression);
    
    // Write truth table rows
    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < varCount; col++) {
            fprintf(file, "%c ", resultTable[row][col] ? 'T' : 'F');
        }
        fprintf(file, "| %c\n", resultTable[row][varCount] ? 'T' : 'F');
    }
    
    fprintf(file, "---------------------------------\n");
    
    // Write verdict
    if (verdict != NULL && strlen(verdict) > 0) {
        fprintf(file, "Verdict: %s\n", verdict);
    }
    if (counterexample != NULL && strlen(counterexample) > 0) {
        fprintf(file, "%s\n", counterexample);
    }
    
    fclose(file);
    cout << "Results saved to " << filename << endl;
}

/*
 * saveResultsToCsv - Save results to a CSV file (spreadsheet-friendly)
 * 
 * @param filename: Name of the file to save
 * @param expression: The expression being analyzed
 * @param vars: Variable names
 * @param varCount: Number of variables
 * @param resultTable: Truth table results
 * @param rowCount: Number of rows
 */
void saveResultsToCsv(const char* filename, const char* expression,
                      char vars[], int varCount,
                      int resultTable[][MAX_VARS + MAX_SUBEXPR + 1],
                      int rowCount) {
    
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        cout << "Error: Could not open file " << filename << " for writing" << endl;
        return;
    }
    
    // Write header row
    for (int i = 0; i < varCount; i++) {
        fprintf(file, "%c,", vars[i]);
    }
    fprintf(file, "%s\n", expression);
    
    // Write data rows
    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < varCount; col++) {
            fprintf(file, "%d,", resultTable[row][col]);
        }
        fprintf(file, "%d\n", resultTable[row][varCount]);
    }
    
    fclose(file);
    cout << "Results saved to " << filename << endl;
}

/*
 * promptSaveResults - Ask user if they want to save and handle saving
 * 
 * @param expression: Expression to save
 * @param vars: Variables
 * @param varCount: Number of variables
 * @param resultTable: Results table
 * @param rowCount: Number of rows
 * @param verdict: Verdict string
 * @param counterexample: Counterexample if any
 */
void promptSaveResults(const char* expression, char vars[], int varCount,
                       int resultTable[][MAX_VARS + MAX_SUBEXPR + 1],
                       int rowCount, const char* verdict, const char* counterexample) {
    
    char choice;
    cout << "\nDo you want to save results? (Y/N): ";
    cin >> choice;
    cin.ignore();  // Clear the newline
    
    if (choice == 'Y' || choice == 'y') {
        char filename[64];
        cout << "Enter filename (without extension): ";
        cin.getline(filename, 64);
        
        char txtFilename[80], csvFilename[80];
        sprintf(txtFilename, "%s.txt", filename);
        sprintf(csvFilename, "%s.csv", filename);
        
        saveResultsToTxt(txtFilename, expression, vars, varCount, 
                         resultTable, rowCount, verdict, counterexample);
        saveResultsToCsv(csvFilename, expression, vars, varCount,
                         resultTable, rowCount);
    }
}

// =============================================================================
// SECTION 14: INPUT HELPERS
// =============================================================================

/*
 * getExpressionInput - Safely get an expression from user
 * 
 * @param prompt: The prompt to display
 * @param buffer: Buffer to store input
 * @return: true if input received, false if empty
 */
bool getExpressionInput(const char* prompt, char* buffer) {
    cout << prompt;
    cin.getline(buffer, MAX_EXPR_LEN);
    
    // Check if empty
    if (strlen(buffer) == 0) {
        return false;
    }
    return true;
}

/*
 * getIntInput - Safely get an integer from user
 * 
 * @param prompt: The prompt to display
 * @param min: Minimum valid value
 * @param max: Maximum valid value
 * @return: The integer entered
 */
int getIntInput(const char* prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        
        cin.ignore();  // Clear newline
        
        if (value < min || value > max) {
            cout << "Please enter a value between " << min << " and " << max << endl;
            continue;
        }
        
        return value;
    }
}

// =============================================================================
// SECTION 15: MENU HANDLERS
// =============================================================================

/*
 * handleTruthTableGeneration - Menu option 1: Generate truth table
 */
void handleTruthTableGeneration() {
    cout << "\n=== Truth Table Generator ===" << endl;
    
    char expression[MAX_EXPR_LEN];
    if (!getExpressionInput("Enter logical expression: ", expression)) {
        cout << "Error: Empty expression" << endl;
        return;
    }
    
    int resultTable[MAX_ROWS][MAX_VARS + MAX_SUBEXPR + 1];
    int rowCount = 0;
    
    generateTruthTable(expression, false, resultTable, &rowCount);
    
    if (rowCount > 0) {
        // Get variables for saving
        char tokens[MAX_TOKENS][MAX_TOKEN_LEN];
        char errorMsg[MAX_EXPR_LEN];
        char vars[MAX_VARS + 1];
        
        int tokenCount = tokenize(expression, tokens, errorMsg);
        if (tokenCount > 0) {
            int varCount = extractVariables(tokens, tokenCount, vars);
            promptSaveResults(expression, vars, varCount, resultTable, rowCount, "", "");
        }
    }
}

/*
 * handleArgumentValidation - Menu option 2: Validate argument
 */
void handleArgumentValidation() {
    cout << "\n=== Argument Validator ===" << endl;
    
    int premiseCount = getIntInput("Enter number of premises (1-5): ", 1, MAX_PREMISES);
    
    char premises[MAX_PREMISES][MAX_EXPR_LEN];
    char conclusion[MAX_EXPR_LEN];
    
    cout << "\nEnter premises (use !, &, |, >, = for operators):" << endl;
    for (int i = 0; i < premiseCount; i++) {
        char prompt[64];
        sprintf(prompt, "Premise %d: ", i + 1);
        if (!getExpressionInput(prompt, premises[i])) {
            cout << "Error: Empty premise" << endl;
            return;
        }
    }
    
    if (!getExpressionInput("Conclusion: ", conclusion)) {
        cout << "Error: Empty conclusion" << endl;
        return;
    }
    
    char counterexample[MAX_EXPR_LEN];
    bool isValid = validateArgument(premises, premiseCount, conclusion, counterexample);
    
    cout << "\n";
    if (isValid) {
        cout << "RESULT: The argument is VALID." << endl;
        cout << "Whenever all premises are true, the conclusion is also true." << endl;
    } else {
        cout << "RESULT: The argument is INVALID." << endl;
        cout << counterexample << endl;
    }
    
    // Prepare for saving
    char allExprs[MAX_PREMISES + 1][MAX_EXPR_LEN];
    for (int i = 0; i < premiseCount; i++) {
        strcpy(allExprs[i], premises[i]);
    }
    strcpy(allExprs[premiseCount], conclusion);
    
    char vars[MAX_VARS + 1];
    int varCount = extractVariablesFromMultiple(allExprs, premiseCount + 1, vars);
    
    int resultTable[MAX_ROWS][MAX_VARS + MAX_SUBEXPR + 1];
    // For saving, we just use a dummy table
    int rowCount = 1 << varCount;  // 2^varCount
    
    char verdict[64];
    strcpy(verdict, isValid ? "Valid" : "Invalid");
    
    promptSaveResults(conclusion, vars, varCount, resultTable, 0, 
                      verdict, isValid ? "" : counterexample);
}

/*
 * handleEquivalenceCheck - Menu option 3: Check equivalence
 */
void handleEquivalenceCheck() {
    cout << "\n=== Logical Equivalence Checker ===" << endl;
    
    char expr1[MAX_EXPR_LEN], expr2[MAX_EXPR_LEN];
    
    if (!getExpressionInput("Enter first expression: ", expr1)) {
        cout << "Error: Empty expression" << endl;
        return;
    }
    
    if (!getExpressionInput("Enter second expression: ", expr2)) {
        cout << "Error: Empty expression" << endl;
        return;
    }
    
    char differences[1024];
    bool isEquivalent = checkEquivalence(expr1, expr2, differences);
    
    cout << "\n";
    if (isEquivalent) {
        cout << "RESULT: The expressions are LOGICALLY EQUIVALENT." << endl;
        cout << "They have the same truth value for all possible inputs." << endl;
    } else {
        cout << "RESULT: The expressions are NOT equivalent." << endl;
        cout << "Rows where they differ:" << endl;
        cout << differences;
    }
    
    // Prepare for saving
    char allExprs[2][MAX_EXPR_LEN];
    strcpy(allExprs[0], expr1);
    strcpy(allExprs[1], expr2);
    
    char vars[MAX_VARS + 1];
    int varCount = extractVariablesFromMultiple(allExprs, 2, vars);
    
    int resultTable[MAX_ROWS][MAX_VARS + MAX_SUBEXPR + 1];
    
    char verdict[64];
    strcpy(verdict, isEquivalent ? "Equivalent" : "Not Equivalent");
    
    char combined[MAX_EXPR_LEN * 2];
    sprintf(combined, "%s vs %s", expr1, expr2);
    
    promptSaveResults(combined, vars, varCount, resultTable, 0,
                      verdict, isEquivalent ? "" : differences);
}

/*
 * handleReasoningChain - Menu option 4: Reasoning chain simulator
 */
void handleReasoningChain() {
    cout << "\n=== Reasoning Chain / Proof Simulator ===" << endl;
    cout << "Enter implications in the form: P > Q" << endl;
    
    int premiseCount = getIntInput("Enter number of premises (1-5): ", 1, MAX_PREMISES);
    
    char premises[MAX_PREMISES][MAX_EXPR_LEN];
    
    for (int i = 0; i < premiseCount; i++) {
        char prompt[64];
        sprintf(prompt, "Premise %d: ", i + 1);
        if (!getExpressionInput(prompt, premises[i])) {
            cout << "Error: Empty premise" << endl;
            return;
        }
    }
    
    char target[MAX_EXPR_LEN];
    cout << "Enter target conclusion to check (or press Enter to skip): ";
    cin.getline(target, MAX_EXPR_LEN);
    
    simulateReasoningChain(premises, premiseCount, 
                           strlen(target) > 0 ? target : NULL);
}

/*
 * displayWelcome - Display welcome message and instructions
 */
void displayWelcome() {
    cout << "\n";
    cout << "============================================================" << endl;
    cout << "     AUTOMATED LOGICAL REASONING SYSTEM (ALRS)" << endl;
    cout << "============================================================" << endl;
    cout << "\n";
    cout << "Supported Operators:" << endl;
    cout << "  !  - NOT (negation)           Example: !P" << endl;
    cout << "  &  - AND (conjunction)        Example: P & Q" << endl;
    cout << "  |  - OR (disjunction)         Example: P | Q" << endl;
    cout << "  >  - IMPLIES (implication)    Example: P > Q" << endl;
    cout << "  =  - EQUIVALENT (biconditional) Example: P = Q" << endl;
    cout << "\n";
    cout << "Variables: Use single uppercase letters (P, Q, R, S, T)" << endl;
    cout << "Parentheses: Use ( ) to group sub-expressions" << endl;
    cout << "\n";
    cout << "Examples:" << endl;
    cout << "  (P & Q) > R     means: If P and Q, then R" << endl;
    cout << "  !P | Q          means: Not P, or Q" << endl;
    cout << "  (P > Q) = (!Q > !P)  means: Contrapositive equivalence" << endl;
    cout << "\n";
}

/*
 * displayMenu - Display main menu and get user choice
 * 
 * @return: User's menu choice (1-6)
 */
int displayMenu() {
    cout << "\n";
    cout << "============ MAIN MENU ============" << endl;
    cout << "1. Generate truth table for expression" << endl;
    cout << "2. Validate an argument (premises -> conclusion)" << endl;
    cout << "3. Check equivalence of two expressions" << endl;
    cout << "4. Reasoning Chain / Derive implications" << endl;
    cout << "5. View help / instructions" << endl;
    cout << "6. Exit" << endl;
    cout << "====================================" << endl;
    
    return getIntInput("Enter your choice (1-6): ", 1, 6);
}

// =============================================================================
// SECTION 16: MAIN FUNCTION
// =============================================================================

/*
 * main - Entry point of the program
 * 
 * Runs the main menu loop and dispatches to appropriate handlers
 */
int main() {
    displayWelcome();
    
    bool running = true;
    
    while (running) {
        int choice = displayMenu();
        
        switch (choice) {
            case 1:
                handleTruthTableGeneration();
                break;
                
            case 2:
                handleArgumentValidation();
                break;
                
            case 3:
                handleEquivalenceCheck();
                break;
                
            case 4:
                handleReasoningChain();
                break;
                
            case 5:
                displayWelcome();
                break;
                
            case 6:
                cout << "\nThank you for using ALRS. Goodbye!" << endl;
                running = false;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}

// =============================================================================
// END OF PROGRAM
// =============================================================================
