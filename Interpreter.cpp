#include "SymbolTable.h"
#include "Parse.h"
#include "Interpreter.h"
#include <iostream>
#include <stdexcept>

using namespace std;

static SymbolTable symtab;

static int evalExpr();
static void handleVar();
static void handleSet();
static void handleOutput();
static void handleText();

void run() {
	read_next_token();

	while (next_token_type != END) {
		if (next_token_type == SYMBOL && string(next_token()) == "//") {
			skip_line();
			read_next_token();
			continue;
		}

		if (next_token_type == NAME) {
			string keyword = next_token();
			if (keyword == "var") {
				handleVar();
			} 
			else if (keyword == "set") {
				handleSet();
			}
			else if (keyword == "output") {
				handleOutput();
			}
			else if (keyword == "text") {
				handleText();			
			}
			else {
				skip_line();	
			}
		
		}
	
		read_next_token();	
	}

}

static int evalExpr() {
	read_next_token();
	if (next_token_type == NUMBER) {
		return token_number_value;
	}	

	if (next_token_type == NAME) {
		return symtab.get(next_token());
	}

	string op = next_token();
	if (op == "!") {
		int v = evalExpr();
		return v == 0 ? 1 : 0;
	}

	if (op == "~") {
		int v = evalExpr();
		return -v;
	}

	int a = evalExpr();
	int b = evalExpr();
	if (op == "+") { return a + b; }
	else if (op == "-") { return a - b; }
	else if (op == "*") { return a * b; }
	else if (op == "/") { return a / b; }
	else if (op == "%") { return a % b; }
	else if (op == "&&") { return (a && b) ? 1 : 0; }
	else if (op == "||") { return (a || b) ? 1 : 0; }
	else if (op == "<") { return (a < b) ? 1 : 0; }
	else if (op == ">") { return (a > b) ? 1 : 0; }
	else if (op == "==") { return (a == b) ? 1 : 0; }
	else if (op == "!=") { return (a != b) ? 1 : 0; }
	else if (op == "<=") { return (a <= b) ? 1 : 0; }
	else if (op == ">=") { return (a >= b) ? 1 : 0; }
	
	throw runtime_error("unknown operator: " + op);
}

static void handleVar() {
	read_next_token();
	string name = next_token();;

	if (symtab.exists(name)) {
		cout << "variable " << name << " incorrectly re-initalized\n";
	}
	
	int val = evalExpr();
	symtab.set(name, val);
}

static void handleSet() {
	read_next_token();
	string name = next_token();;

	if (!symtab.exists(name)) {
		cout << "variable " << name << " not declared\n";
	}

	int val = evalExpr();
	symtab.set(name,val);
}

static void handleOutput() {
	int val = evalExpr();
	cout << val;
}

static void handleText() {
	read_next_token();
	cout << next_token();
}












