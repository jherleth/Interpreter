#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <map>
#include <string>
#include <stdexcept>

using namespace std;

class SymbolTable {
public:
	bool exists(const string &name) const { return table.find(name) != table.end(); }
	
	int get(const string &name) const {
		map<string, int>::const_iterator it = table.find(name);
		if (it == table.end()) {
			throw runtime_error("undefined variable" + name);
		}
		return it->second;
	}
	
	void set(const string &name, int value) {
		table[name] = value;
	}
private:
	map<string, int> table;
};

#endif
