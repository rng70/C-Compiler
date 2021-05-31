%{
#include<bits/stdc++.h>
#include "SymbolTable.cpp"

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

extern int numberOfLines;
extern int numberOfErrors;

FILE* logs;
FILE* errors;

SymbolTable symbolTable(7);
// Symbol Set(s)
map<string, string> SymbolSet;
vector< pair<string,string> >temp_param_list;
vector< pair<string,string> >arg_param_list;
vector<SymbolInfo*>v;

// error detection
void yyerror(const char *s){
    fprint(errors, "Line no %d: %s\n", numberOfLines, s);
}

void symbolSet()
{
    SymbolSet["comma"] = ",";
	SymbolSet["semicolon"] = ";";
	SymbolSet["left_third"] = "[";
	SymbolSet["right_third"] = "]";
	SymbolSet["newline"] = "\n";
	SymbolSet["left_first"] = "(";
	SymbolSet["right_first"] = ")";
	SymbolSet["equal"] = "=";
	SymbolSet["plus"] = "+";
	SymbolSet["minus"] = "-";
	SymbolSet["left_curl"] = "{";
	SymbolSet["right_curl"] = "}";
	SymbolSet["incop"] = "++";
	SymbolSet["decop"] = "--";
}
// get it
string getFromSymbolSet(string name)
{
	return SymbolSet.at(name);
}
%}

%union{
    SymbolInfo* symbolInfoPointer;
}
%token FOR IF DO INT FLOAT VOID COMMA SEMICOLON
%token ELSE WHILE DOUBLE CHAR RETURN CONTINUE
%token PRINTLN  ASSIGNOP LPAREN RPAREN
%token LCURL RCURL LTHIRD RTHIRD
%token<symbolInfoPointer>CONST_INT
%token<symbolInfoPointer>CONST_FLOAT
%token<symbolInfoPointer>CONST_CHAR
%token<symbolInfoPointer>ADDOP
%token<symbolInfoPointer>MULOP
%token<symbolInfoPointer>LOGICOP
%token<symbolInfoPointer>BITOP
%token<symbolInfoPointer>RELOP
%token<symbolInfoPointer>INCOP
%token<symbolInfoPointer>DECOP
%token<symbolInfoPointer>ID
%token<symbolInfoPointer>NOT

%type <symbolInfoPointer> expression logic_expression simple_expression rel_expression  type_specifier term unary_expression variable factor statement expression_statement  compound_statement  declaration_list var_declaration statements func_declaration  func_definition parameter_list unit program argument_list arguments

// This is the starting point of implementation of bison grammar 

%%
start : program {
	fprintf(logs, "Symbol Table: \n\n");
	symbolTable.printAll(logs);
};

program : program unit {
	fprintf(logs, "At line no: %d program : program unit\n\n", numberOfLines);
	$$ -> extraSymbolInfo.stringAdder(getFromSymbolSet(newline) + extraSymbolInfo.stringConcatenator);
	fprintf(logs,"%s\n\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
	} | unit {
	fprintf(logs, "At line no: %d program : program unit\n\n", numberOfLines);
	$$ -> extraSymbolInfo.stringConcatenator = $1 -> extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
};

unit : var_declaration{
	fprintf(logs, "At line no: %d unit : var_declaration\n\n", numberOfLines);
	$$ -> extraSymbolInfo.stringConcatenator = $1-> extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
} | func_declaration{
	fprintf(logs, "At line no: %d unit : func_declaration\n\n", numberOfLines);
	$$ -> extraSymbolInfo.stringConcatenator = $1-> extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
} | func_definition{
	fprintf(logs, "At line no: %d unit : func_definition\n\n", numberOfLines);
	$$ -> extraSymbolInfo.stringConcatenator = $1-> extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
};

func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON{
	/* We need to check some properties of function declaration in this step:
			1. Check return type is same
			2. Check number of parameter is same
			3. Check parameter sequence is same
			4. No void Parameters are declared
			*/
	fpirntf(logs, "At line no: %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n", numberOfLines);
	SymbolInfo* temp = symbolInfoPointer.LookUP($2->getName());

	// if it found in symbol table
	if(temp != 0){

		// Checking return type
		if(temp->extraSymbolInfo.returnTypeOfFunction != $1->getType()){
			numberOfErrors++;
			fprintf(errors, "Error at line %d : Return Type Mismatch of function declaration\n\n", numberOfLines);
		}

		// Checking parameter
		if(temp->extraSymbolInfo.functionParamList.size()!=temp_param_list.size()){
			numberOfErrors++;
			fprintf(errors, "Error at line %d: Unequal number of parameters\n\n", numberOfLines++);
			temp_param_list.clear();
		}
		// Checking parameter sequence
		else{
			for(int i=0;i<temp_param_list.size();i++){
				if(temp_param_list[i].second != functionParamList[i].second){
					numberOfErrors++;
					fprintf(errors, "Argument Type Mismatch with previous function declaration \n\n", numberOfLines);
				}
			}
			temp_param_list.clear();
		}
	}
	// if not found in symbol table
	else{
		// variable to check void type
		bool isVoid = false;
		// checking no void parameter is declared
		for(int i=0;i<temp_param_list.size();i++){
			if(temp_param_list[i].second=="VOID"){
				isVoid = true; 
				break;
			}
		}
		SymbolInfo* temp = new SymbolInfo();
		temp->extraSymbolInfo.typeOfID = "FUNCTION";
		temp->extraSymbolInfo.returnTypeOfFunction = $1->getType();
		temp->extraSymbolInfo.isFunction = true;
		temp->extraSymbolInfo.isFunctionDeclared = true;
		temp.setName($2->getName());
		temp.setType($2->getType());

		if(isVoid){
			numberOfErrors++;
			fprintf(errors, "Error at line %d: Parameter cannot be void \n\n", line_counter);
			temp->extraSymbolInfo.is_function = false;
		}
		for(int i=0;i<temp_param_list.size();i++){
			temp->extraSymbolInfo.functionParamList.push_back(make_pair(temp_param_list[i].first, temp_param_list[i].second));
		}
		temp_param_list.clear();
		symbolTable.insertModified(temp);
	}
	$$ -> extraSymbolInfo.stringConcatenator = $1->extraSymbolInfo.stringConcatenator + $2->getName()+getFromSymbolSet("left_first")+$4->extraSymbolInfo.stringConcatenator+getFromSymbolSet("right_first")+getFromSymbolSet("semicolon");
	fprintf(logs, "%s\n\n\n", $$->extraSymbolInfo.stringConcatenator.c_str());
} | type_specified ID LPAREN RPAREN SEMICOLON {
	fprintf(logs, "At line no: %d func_declaration : type_specified ID LPAREN RPAREN SEMICOLON\n\n", numberOfLines);
	SymbolInfo* temp = symbolTable.LookUp($2->getName());
	if(temp != 0){
		if(temp->extraSymbolInfo.returnTypeOfFunction != $1->getType()){
			numberOfErrors++;
			fprintf(errors, "Error at Line %d: Return Type Mismatch of function declaration \n\n", numberOfLines);
		}
		if(temp->extraSymbolInfo.functionParamList.size()!=0){
			error_counter++;
			fprintf(errors, "Error at Line %d : Unequal number of parameters\n\n", numberOfLines);
			temp_param_list.clear();
		} }else{
			SymbolInfo* temp = new SymbolInfo();
			temp->extraSymbolInfo.typeOfID = "FUNCTION";
			temp->extraSymbolInfo.returnTypeOfFunction = $1->getType();
			temp->extraSymbolInfo.isFunction = true;
			temp->extraSymbolInto.isFunctionDeclared = true;
			temp->setName($2->getName());
			temp->setType($2->getType());

			for(int i=0;i<temp_param_list.size();i++){
				temp->extraSymbolInfo.functionParamList.push_back(make_pair(temp_param_list[i].first, temp_param_list[i].second));
			}
			temp_param_list.clear();
			symbolTable.InsertModified(temp);
		}
		$$ -> extraSymbolInfo.stringConcatenator = $1->extraSymbolInfo.stringConcatenator + $2->getName()+getFromSymbolSet("left_first")+getFromSymbolSet("right_first")+getFromSymbolSet("semicolon");
	fprintf(logs, "%s\n\n\n", $$->extraSymbolInfo.stringConcatenator.c_str());
};

func_definition : type_specified ID LPAREN parameter_list RPAREN compound_statement {
		// scope_counter = scope_counter + 1
		printf(logs, "At line no: %d func_definition : type_specified ID LPAREN parameter_list RPAREN compound_statement\n\n", numberOfLines);
		SymbolInfo *s = symbolTable.LookUP($2->getName());
		SymbolInfo *temp = new SymbolInfo();
		bool flag = true;
		// if it doest not exixts in any scope then insert the ID into
		if(s==0){
			bool check = false;
			for(int i=0;i<temp_param_list.size();i++){
				if(temp_param_list[i].second == "VOID"){
					check = true;
				}
			}

			// make a new object to insert into Symbol Table
			temp->extraSymbolInfo.typeOfID = "FUNCTION";
			temp->extraSymbolInfo.returnTypeOfFunction = $1->getType();
			temp->extraSymbolInfo.isFunction = true;
			temp->extraSymbolInfo.isFunctionDefined = true;
			temp->setName($2->getName());
			temp->setType($2->getType());

			if(check){
				numberOfErrors++;
				fprintf(errors, "Error at line %d : Parameter cannot be VOID\n\n", numberOfLines);
				temp->extraSymbolInfo.isFunction=false;
			}

			for(int i=0;i<temp_param_list.size();i++){
				temp->extraSymbolInfo.functionParamList.push_back(make_pair(temp_param_list[i].first, temp_param_list[i].second));
				// string t = temp_param_list[i].first+to_string(scope_counter);
				// temp->extra_var.modfd_param_list.push_back(t);               
				// pushing to the modified paramater list of the pointer
			}

			/*if(return_type_solver!=$1->getType())
			{
				error_counter++;
				fprintf(errors,"Error at Line %d : return type error \n\n",line_counter);
				return_type_solver="";
				temp->extra_var.is_function=false;
			}*/
			symbolTable.InsertModified(temp);
		}
		// if it already exists in global scope
		else{
			// function already exists
			if(s->extraSymbolInfo.isFunctionDefined){
				numberOfErrors++;
				fprint(errors, "Error at line %d: Multiple definition of function\n\n", numberOfLines);
				temp_param_list.clear();
			}else if(s->extraSymbolInfo.isFunctionDeclared){
				/* Three case to handle here 
				1. Return type check 
				2. Check number of parameters and
				3. Check for sequence of parameters */
				s->extraSymbolInfo.isFunctionDefined = true;
				string actReturnType = $1->getType();
				string declaredReturnType = s->extraSymbolInfo.returnTypeOfFunction;
				string declaredParamSize = s->extraSymbolInfo.functionParamList.size();string definedParamSize = temp_param_list.size();

				// Case 1: Return type Check
				if(actReturnType != declaredReturnType){
					numberOfErrors++;
					fprintf(errors, "Error at line %d: Return type mismatch\n\n", numberOfLines);
					flag = false;
				}
				// Case 2: Check for size of paramter list
				else if(definedParamSize != definedParamSize){
					numberOfErrors++;
					fprintf(errors, "Error at line %d: Unequal number of parameters\n\n", numberOfLines);
					temp_param_list.clear();
					flag = false;
				}
				// Case 3: Check for sequence of parameter list 
				else{
					for(int i = 0;i<temp_param_list.size();i++){
						if(temp_param_list[i].second != functionParamList[i].second){
							numberOfErrors++;
							fprintf(errors, "Error at line %d: Argument Type Mismathch with function declaration\n\n", numberOfLines);
							flag=false;
							break;
						}
					}
					temp_param_list.clear();
					/* for(int i =0;i<temp_param_list.size();i++)
					{
						string t = temp_param_list[i].first+to_string(scope_counter);
						s->extra_var.modfd_param_list.push_back(t);               //pushing to the modified paramater list of the pointer
					} */
				}
				if(return_type_solver!=$1->getType())
				{

					numberOfErrors++;
					fprintf(errors,"Error at Line %d : return type error \n\n",numberOfLines);
					return_type_solver="";
					flag=false;
				}
			}
		}
		$$->extraSymbolInfo.stringConcatenator = $1->extraSymbolInfo.stringConcatenator+$2->getName()+getFromSymbolset("left_first")+$4->extraSymbolInfo.stringConcatenator+getFromSymbolset("right_first")+$6->extraSymbolInfo.stringConcatenator;
		fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
} | type_specified ID LPAREN compound_statement{
	fprintf(logs, "At line no: %d func_definition ID LPAREN RPAREN compound_statement\n\n", numberOfLines);

	// scope_counter++;
	SymbolInfo *s = symbolTable.LookUp($2->getName());

	if(s==0){
		SymbolInfo* temp = new SymbolInfo();
		temp->extraSymbolInfo.typeOfID = "FUNCTION";
		temp->extraSymbolInfo.returnTypeOfFunction = $1->getType();
		temp->extraSymbolInfo.isFunction = true;
		temp->extraSymbolInfo.isFunctionDefined = true;
		temp->setName($2->getName());
		temp->getType($2->getName());

		symbolTable.InsertModified(temp);
	}else{
		if(s->extraSymbolInfo.isFunctionDeclared){
			string actReturnType = $1->getType();
			string funcReturnType = s->extraSymbolInfo.returnTypeOfFunction;

			if(actReturnType != funcReturnType){
				numberOfErrors++;
				fprinf(errors, "Error at line %d: Return type mismatch\n\n", numberOfLines);
				s->extraSymbolInfo.isFunction = false;
			}
		}else if(s->extraSymbolInfo.isFunctionDefined){
			numberOfErrors++;
			fprintf(errors,"Error at Line %d :Multiple defination of function\n\n",numberOfLines);
			temp_param_list.clear();
		}
	}
	$$->extraSymbolInfo.stringConcatenator = $1->extraSymbolInfo.stringConcatenator+$2->getName()+getFromSymbolSet("left_first")+getFromSymbolSet("right_first")+$5->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str())
};

parameter_list  : parameter_list COMMA type_specifier ID
{
		fprintf(logs,"At line no: %d parameter_list  : parameter_list COMMA type_specifier ID\n\n",numberOfLines);
		temp_param_list.push_back(make_pair($4->getName(),$3->getType()));
		$$->extraSymbolInfo.stringConcatenator = $1->extraSymbolInfo.stringConcatenator+getFromSymbolSet("comma")+$3->extraSymbolInfo.stringConcatenator+$4->getName();
		fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
}
| parameter_list COMMA type_specifier
{
		fprintf(logs,"At line no: %d parameter_list  : parameter_list COMMA type_specifier\n\n",numberOfLines);
		temp_param_list.push_back(make_pair("",$3->getType()));
		$$->extraSymbolInfo.stringConcatenator = $1->getName()+getFromSymbolSet("comma")+$3->extraSymbolInfo.stringConcatenator;
		fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
}
| type_specifier ID
{
		fprintf(logs,"At line no: %d parameter_list  : type_specifier ID\n\n", numberOfLines);
		temp_param_list.push_back(make_pair($2->getName(),$1->getType()));
		$$->extraSymbolInfo.stringConcatenator = $1->extraSymbolInfo.stringConcatenator.append($2->getName());
		fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());

}
| type_specifier
{
		fprintf(logs,"At line no: %d parameter_list  : type_specifier\n\n",numberOfLines);
		temp_param_list.push_back(make_pair("",$1->getType()));
		$$->extraSymbolInfo.stringConcatenator =$1->extraSymbolInfo.stringConcatenator;
		fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
};

compound_statement : LCURL {
	symbolTable.EnterScope();

	scope_counter_2 = symbolTable.getTableIdTracker();
	scope_holder = symbolTable.getStringityID();

	if(temp_param_list.size()!=0){
		for(int i=0;i<temp_param_list.size();i++){
			string name = temp_param_list[i].first;
			string type = temp_param_list[i].second;

			SymbolInfo *s = new SymbolInfo();
			s->setName(name);
			s->setType("ID");
			s->extraSymbolInfo.typeOfVar = type;
			bool check = symbolTable.InsertModified(s);

			if(check == 0){
				numberOfErrors++;
				fprintf(errors, "Error at line %d: Duplicate Parameter Name of function\n\n", numberOfLines);
			}
		}
	}
	temp_param_list.clear();
} statements RCURL {
	fprintf(logs,"At line no: %d compound_statement : LCURL statements RCURL\n\n",numberOfLines);
	$$->extraSymbolInfo.stringConcatenator = getFromSymbolTable("left_curl")+"\n"+$3->extraSymbolInfo.stringConcatenator+getFromSymbolTable("right_curl");
	fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
	symbolTable.printAll(logs);
	symbolTable.ExitScope();
} | LCURL {
	symbolTable.EnterScope();
	// scope_counter_2 = symbolTable.getTableIDTracker();

	for(int i=0;i<temp_param_list.size();i++){
		string name = temp_param_list[i].first;
		string type = temp_param_list[i].second;

		SymbolInfo *s = new SymbolInfo();
		s->setName(name);
		s->setType("ID");
		s->extraSymbolInfo.typeOfVar = type;
		bool check = symbolTable.InsertModified(s);
		symbolTable.printAll(logs);
		//decld_var_carrier.push_back(make_pair(name+to_string(scope_counter),""));

		if(check == 0){
			numberOfErrors++;
			fprintf(errors, "Error at line %d : Duplicate Parameter Name of function\n\n", numberOfLines);
		}
	}
	// temp_param_list.clear();
} RCURL {
	fprintf(logs,"At line no: %d compound_statement : LCURL  RCURL\n\n",numberOfLines);
	$$->extraSymbolInfo.stringConcatenator = getFromSymbolSet("left_curl")+"\n"+getFromSymbolSet("right_curl");
	fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
	symbolTable.printAll(logs);
	symbolTable.ExitScope();
};

var_declaration : type_specifier declaration_list SEMICOLON{
	fprintf(logs,"At line no: %d var_declaration : type_specifier declaration_list SEMICOLON\n\n",numberOfLines);

	$$->extraSymbolInfo.stringConcatenator = string_adder(3,$1->extraSymbolInfo.stringConcatenator.c_str(),$2->extraSymbolInfo.stringConcatenator.c_str(),getFromSymbolSet("semicolon").c_str());

	fprintf(logs,"%s\n\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
};

type_specified : INT {
	fprintf(logs, "At line no: %d type_specifier : INT\n\n", numberOfLines);

	SymbolInfo* s = new SymbolInfo("", "INT");
	type_of_var = "INT";
	$$ = s;
	$$->extraSymbolInfo.stringConcatenator = "int ";
	fprintf(logs, "%s\n\n", $$->extraSymbolInfo.stringConcatenator.c_str());
} | FLOAT {
	fprintf(logs,"At line no: %d type_specifier	: FLOAT\n\n",numberOfLines);
	SymbolInfo* s = new SymbolInfo("","FLOAT");
	type_of_var = "FLOAT";
	$$ = s;
	$$->extraSymbolInfo.stringConcatenator = "float ";
	fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
} | VOID {
	fprintf(logs,"At line no: %d type_specifier	: VOID\n\n",numberOfLines);
	SymbolInfo* s = new SymbolInfo("","VOID");
	type_of_var = "VOID";
	$$ = s;
	$$->extraSymbolInfo.stringConcatenator = "void ";
	fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
};
declaration_list : declaration_list COMMA ID{
	if(type_of_var!="VOID")
	{
	fprintf(logs,"At line no : %d declaration_list : declaration_list COMMA ID\n\n",numberOfLines);

	SymbolInfo* test = symbolTalbe.currentScopeLookUp($3->getName());
	if(test!=0)
	{
		fprintf(errors,"Error at Line %d  : Multiple Declaration of %s\n\n",numberOfLines,$3->getName().c_str());
		numberOfErrors++;
	}
	else
	{
		SymbolInfo* obj = new SymbolInfo($3->getName(),$3->getType());
		obj->extraSymbolInfo.typeOfID = "VARIABLE";
		obj->extraSymbolInfo.typeOfVar = type_of_var;
		symbolTable.Insertmodified(obj);
	}

	$1->extraSymbolInfo.stringConcatenator.append(getFromSymbolInfo("comma"));
	$$->extraSymbolInfo.stringConcatenator.append($3->getName());
	fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
	}
} | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD{
	if(type_of_var!="VOID")
	{
	fprintf(logs,"At line no : %d declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n",numberOfLines);
	SymbolInfo* test = symbolTable.currentScopeLookUp($3->getName());


	if(test!=0)
	{
		fprintf(errors,"Error at Line %d  : Multiple Declaration of %s\n\n",numberOfLines,$3->getName().c_str());
		numberOfErrors++;
	}
	else
	{
		SymbolInfo* obj = new SymbolInfo($3->getName(),$3->getType());

		obj->extraSymbolInfo.typeOfID = "ARRAY";
		obj->extraSymbolInfo.typeOfVar = type_of_var;
		obj->extraSymbolInfo.sizeOfArray = $5->getName();
		symbolTable.Insertmodified(obj);
	}
	string temp = $3->getName()+getFromSymbolSet("left_third")+$5->getName()+getFromSymbolSet("right_third");
	$1->extraSymbolInfo.stringConcatenator.append(m.at("comma"));
	$$->extraSymbolInfo.stringConcatenator.append(temp);
	fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
	}
} | ID {
	fprintf(logs,"At line no : %d declaration_list : ID\n\n",numberOfLines);

	if(type_of_var!="VOID")
	{
		SymbolInfo* temp = symbolTable.currentScopeLookUp($1->getName());
		if(temp!=0)
		{
			numberOfErrors++;
			fprintf(errors,"Error at Line %d  : Multiple declration of %s\n\n",numberOfLines,$1->getName().c_str());
		}else{
			SymbolInfo* obj = new SymbolInfo($1->getName(),$1->getType());
			obj->extraSymbolInfo.typeOfID = "VARIABLE";
			obj->extraSymbolInfo.typeOfVar = type_of_var;
			symbolTable.Insertmodified(obj);
		}
} else{
	numberOfErrors++;
	fprintf(errors,"Error at Line %d  : Variable declared void\n\n",numberOfLines);
}

$$->extraSymbolInfo.stringConcatenator = $1->getName();
fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
} | ID LTHIRD CONST_INT RTHIRD {
	fprintf(logs,"At line no : %d ID LTHIRD CONST_INT RTHIRD\n\n",numberOfLines);

	//checking to see if array type is void or not
	if(type_of_var!="VOID")
	{
		//check for array ID in symbol table, if does not exist, insert it,else generate error.
		SymbolInfo* temp = symbolTable.currentScopeLookUp($1->getName());
		if(temp!=0)
		{
			fprintf(errors,"Error at Line %d  : Multiple declration of %s\n\n",numberOfLines,$1->getName().c_str());
			numberOfErrors++;
		}else{
			SymbolInfo* obj = new SymbolInfo($1->getName(),$1->getType());
			obj->extraSymbolInfo.typeOfID = "ARRAY";
			obj->extraSymbolInfo.typeOfVar = type_of_var;
			obj->extraSymbolInfo.sizeOfArray = $3->getName();
			symbolTable.Insertmodified(obj);
		}
	} else {
		fprintf(errors,"Error at Line %d  :  Array %s declared as void\n\n", numberOfLines,$1->getName().c_str());
		numberOfErrors++;
	}
    string temp = getFromSymbolSet("left_third")+$3->getName()+getFromSymbolSet("right_third");
	$$->extraSymbolInfo.stringConcatenator = $1->getName();
	$$->extraSymbolInfo.stringConcatenator.append(temp);
	fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
};
statements : statement{
	fprintf(logs,"At line no : %d statements : statement\n\n",numberOfLines);
	$$->extraSymbolInfo.stringConcatenator = $1->extraSymbolInfo.stringConcatenator+"\n";
	fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
} | statements statement {
	fprintf(logs,"At line no : %d statements : statements statement\n\n", numberOfLines);
	$$->extraSymbolInfo.stringConcatenator = $1->extraSymbolInfo.stringConcatenator+($2->extraSymbolInfo.stringConcatenator+"\n");
	statement_solver = $$->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
};
statement : var_declaration {
	fprintf(logs,"At line no: %d statement : var_declaration\n\n",numberOfLines);
	$$->extraSymbolInfo.stringConcatenator = $1->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
	} | expression_statement {
	fprintf(logs,"At line no: %d statement : expression_statement\n\n",numberOfLines);
	$$->extraSymbolInfo.stringConcatenator = $1->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
} | compound_statement {
	fprintf(logs,"At line no: %d statement : compound_statement\n\n",numberOfLines);
	$$->extraSymbolInfo.stringConcatenator = $1->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
} | FOR LPAREN expression_statement expression_statement expression RPAREN statement {
	fprintf(logs,"At line no: %d statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n",numberOfLines);
	string temp = $3->extraSymbolInfo.join_string($4->extraSymbolInfo.join_string($5->extraSymbolInfo.stringConcatenator));
	$$->extraSymbolInfo.stringConcatenator = "for"+getFromSymbolSet("left_first")+temp+getFromSymbolSet("right_first")+$7->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());

	//var type of expression_statements and expression
	string a = $3->extraSymbolInfo.typeOfVar;
	string b = $4->extraSymbolInfo.typeOfVar;
	string c = $5->extraSymbolInfo.typeOfVar;

	if((a=="VOID")||(b=="VOID")||(c=="VOID"))
	{
		numberOfErrors++;
		fprintf(errors,"Error at Line %d : Expression can not be void\n\n",numberOfLines);
	}
} | IF LPAREN expression RPAREN statement %prec LOWER_PREC_THAN_ELSE
	{
		fprintf(logs,"At line no: %d IF LPAREN expression RPAREN statement\n\n",numberOfLines);
		string temp = $3->extraSymbolInfo.join_string(m.at("right_first"));
		$$->extraSymbolInfo.stringConcatenator = "if"+m.at("left_first")+temp+$5->extraSymbolInfo.stringConcatenator;
		fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());

		string a = $3->extraSymbolInfo.typeOfVar;
		if(a=="VOID")
		{
			numberOfErrors++;
			fprintf(errors,"Error at Line %d : Expression can not be void\n\n",numberOfLines);
		}
	} | IF LPAREN expression RPAREN statement ELSE statement {
		fprintf(logs,"At line no : %d IF LPAREN expression RPAREN statement ELSE statement\n\n",line_counter);
		string temp = $3->extra_var.join_string(m.at("right_first"));
		string temp2 = $5->extra_var.join_string("else"+$7->extra_var.concatenator);
		$$->extra_var.concatenator = "if"+m.at("left_first")+temp+temp2;
		fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());

		string a = $3->extra_var.var_type;
		if(a=="VOID")
		{
			error_counter++;
			fprintf(errors,"Error at Line %d : Expression can not be void\n\n",line_counter);
		}

	} 	  | WHILE LPAREN expression RPAREN statement
	  {
		  fprintf(logs,"At line no: %d WHILE LPAREN expression RPAREN statement\n\n",line_counter);
		  string temp = $3->extra_var.join_string(m.at("right_first")+$5->extra_var.concatenator);
		  $$->extra_var.concatenator = "while"+m.at("left_first")+temp;
		  fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());

			string a = $3->extra_var.var_type;
			if(a=="VOID")
			{
				error_counter++;
				fprintf(errors,"Error at Line %d : Expression can not be void\n\n",line_counter);
			}

	  } 	  | PRINTLN LPAREN ID RPAREN SEMICOLON
	  {
		  fprintf(logs,"At line no: %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n",line_counter);
		//   string temp = $3->extra_var.join_string(m.at("right_first")+m.at("semicolon"));
		//   $$->extra_var.concatenator = "println"+m.at("left_first")+temp;
		$$->extra_var.concatenator = "println"+m.at("left_first")+$3->getName()+m.at("right_first")+m.at("semicolon");
		  fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());

	  } 	  | RETURN expression SEMICOLON
	  {
		  fprintf(logs,"At line no: %d statement : RETURN expression SEMICOLON\n\n",line_counter);
		  $$->extra_var.concatenator = "return "+$2->extra_var.join_string(m.at("semicolon"));
		  fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());

			string a = $2->extra_var.var_type;

			if(a=="VOID")
			{

				error_counter++;
				fprintf(errors,"Error at Line %d : Expression can not be void\n\n",line_counter);

			}
			return_type_solver = a;

};
expression_statement 	: SEMICOLON
						{
							fprintf(logs,"At line no: %d expression_statement : SEMICOLON\n\n",line_counter);
							$$->extra_var.concatenator = m.at("semicolon");
							fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
						}
						| expression SEMICOLON
						{
							fprintf(logs,"At line no: %d expression_statement : expression SEMICOLON\n\n",line_counter);
							$$->extra_var.concatenator = $1->extra_var.join_string(m.at("semicolon"));
							$$->extra_var.var_type = $1->extra_var.var_type;
							fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
						}
						;
variable : ID
		{
			//cout<<"In variable: ID"<<endl;
			fprintf(logs,"At line no: %d variable : ID \n\n",line_counter);
			SymbolInfo* temp =  stable.LookUp($1->getName());
			string type="";
			//cout<<"IN checking = ="<<$1->getName()<<" "<<temp->extra_var.var_type<<endl;
		 	if(temp!=0)
		 	{
				if(temp->extra_var.ID_type=="ARRAY")
				{
					error_counter++;
					fprintf(errors,"Error at Line %d : No index on array\n\n",line_counter,$1->getName().c_str());
					type = temp->extra_var.var_type;
				}
				else if(temp->extra_var.is_function)
				{
					error_counter++;
					fprintf(errors,"Error at Line %d : Improper Function call\n\n",line_counter,$1->getName().c_str());
					type = temp->extra_var.func_ret_type;
				}
				else
				{
					type = temp->extra_var.var_type;
				}

				$$->extra_var.var_type = type;
				$$->extra_var.ID_type = temp->extra_var.ID_type;
				$$->setName(temp->getName());
				$$->setType(temp->getType());
				//cout<<"ekhne"<<endl;
		 	}
			 else //works
		 	{
			 	error_counter++;
			 	fprintf(errors,"Error at Line %d : Undeclared variable : %s\n\n",line_counter,$1->getName().c_str());
		 	}
			//fprintf(logs,"error-verbose at line in undeclraed variable")

			 $$->extra_var.concatenator = $1->getName();
			 fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
			 //fprintf(logs,"type is: %s\n\n",$$->extra_var.var_type.c_str());

		} 	 | ID LTHIRD expression RTHIRD
	 {

		 fprintf(logs,"At line no: %d variable : ID LTHIRD expression RTHIRD\n\n",line_counter);
		 //check to see if ID is in scope table or not
		 SymbolInfo* temp = stable.LookUp($1->getName());
		 //cout<<"IN checking = ="<<$1->getName()<<" "<<temp->extra_var.ID_type<<endl;
		 if(temp!=0)
		 {
			 string id_type = temp->extra_var.ID_type;

			 if(id_type!="ARRAY")
			 {
				 error_counter++;
				 fprintf(errors,"Error at Line %d : Index Not on Array\n\n",line_counter);
			 }
			 else
			 {

					string type = $3->extra_var.var_type; //index expression type
					//cout<<"here"<<endl;
					//int arr_size = stoi(temp->extra_var.array_size); //declared array size

					string arr_type = $1->extra_var.var_type;
					if(type!="INT")
					{
							error_counter++;
							fprintf(errors,"Error at Line %d : Non Integer Array Index\n\n",line_counter);
					}

			 }

			temp->extra_var.is_function ? $$->extra_var.var_type = temp->extra_var.func_ret_type :	$$->extra_var.var_type = temp->extra_var.var_type; //Function retutypeset,else var typeset to result

			$$->extra_var.ID_type = temp->extra_var.ID_type;
			$$->setName(temp->getName());
			$$->setType(temp->getType());
			$$->extra_var.array_index  = temp->extra_var.array_index;
			$$->extra_var.array_size = temp->extra_var.array_size;
		 }
		 else
		 {
			 error_counter++;
			 fprintf(errors,"Error at Line %d : Undeclared variable : %s\n\n",line_counter,$1->getName().c_str());
		 }

		string t = m.at("left_third")+$3->extra_var.join_string(m.at("right_third"));
		$$->extra_var.concatenator = $1->getName()+t;
		fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
	 }
	 ;
 expression : logic_expression
			{
				fprintf(logs,"At line no: %d expression : logic_expression\n\n",line_counter);
				$$->extra_var.concatenator = $1->extra_var.concatenator;
				$$->extra_var.var_type = $1->extra_var.var_type;
				fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
			}
	   | variable ASSIGNOP logic_expression
	   {

			 //cout<<"variable is : "<<$1->extra_var.concatenator<<endl;
		   fprintf(logs,"At line no: %d expression :variable ASSIGNOP logic_expression\n\n",line_counter);

			 SymbolInfo* s = stable.LookUp($1->getName());

			 if(s!=0)
			 {
				 string v_type = s->extra_var.var_type;
				 string log_exp_type = $3->extra_var.var_type;

				 //cout<<"left "<<v_type<<endl;
				 //cout<<"right "<<log_exp_type<<endl;

				 if($3->extra_var.var_type=="VOID")
				 {
						 error_counter++;
						 fprintf(errors,"Error at Line %d : Type Mismatch: cannot assign to VOID type\n\n",line_counter);
				 }
				 else
				 {
						 if(v_type!=log_exp_type)
						{
							//cout<<log_exp_type<<endl;
						  error_counter++;
						  fprintf(errors,"Error at Line %d : Type Mismatch\n\n",line_counter);
						}

						if((v_type=="FLOAT")&&(log_exp_type=="INT"))
						{
						  //error_counter++;
						  fprintf(errors,"Warning at Line %d : Integer assigned to Float\n\n",line_counter);
						//check return type consistencyint
						//check return type consistencyint
						//check return type consistencyint

						}
						else if((v_type=="INT")&&(log_exp_type=="FLOAT"))
						{
						 	//error_counter++;
						 	fprintf(errors,"Warning at Line %d : Float assigned to Integer\n\n",line_counter);
						}
				 }

			 }

		   $$->extra_var.var_type = $1->extra_var.var_type;

		   //cout<<"logic exp is : "<<$3->extra_var.concatenator<<endl;
		   $$->extra_var.concatenator = $1->extra_var.concatenator+m["equal"]+$3->extra_var.concatenator;
		   fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
	   }
	   ;
logic_expression : rel_expression
				 {
					 fprintf(logs,"At line no : %d logic_expression : rel_expression \n\n",line_counter);
					 $$->extra_var.concatenator = $1->extra_var.concatenator;
					 $$->extra_var.var_type = $1->extra_var.var_type;
					 //cout<<"In log_exp: rel_exp "<<$$->extra_var.concatenator<<" "<<$1->extra_var.concatenator<<endl;
					 fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
				 }
		 | rel_expression LOGICOP rel_expression
		 {
			 fprintf(logs,"At line no : %d logic_expression : rel_expression LOGICOP rel_expression \n\n",line_counter);
			 string a_type  = $1->extra_var.var_type;
			 string b_type  =  $2->extra_var.var_type;
			 if((a_type=="VOID") || (b_type =="VOID"))
			 {
				 error_counter++;
				 fprintf(errors,"Error at Line %d  : Type Mismatch: cannot operate on VOID type\n\n",line_counter);
			 }
			 string res_type = "INT";
			 $$->extra_var.var_type = res_type;
			 string temp = $1->extra_var.join_string($2->getName()+$3->extra_var.concatenator);
			 $$->extra_var.concatenator = temp;
			 fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
			 //check for VOID
		 }
		 ;
rel_expression	: simple_expression
				{
					 fprintf(logs,"At line no : %d rel_expression : simple_expression \n\n",line_counter);
					 $$->extra_var.concatenator = $1->extra_var.concatenator;
					 $$->extra_var.var_type = $1->extra_var.var_type;
					 //cout<<"In re_exp:simple_exp: "<<$$->extra_var.concatenator<<" "<<$$->extra_var.concatenator<<endl;
					 fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
				}
		| simple_expression RELOP simple_expression
		{
			fprintf(logs,"At line no : %d rel_expression : simple_expression RELOP simple_expression \n\n",line_counter);

			string a_type  = $1->extra_var.var_type;
			string b_type  =  $2->extra_var.var_type;
			if((a_type=="VOID") || (b_type =="VOID"))
			{
				error_counter++;
				fprintf(errors,"Error at Line %d  : Type Mismatch: cannot operate on VOID type\n\n",line_counter);
			}

			string res_type = "INT";
			$$->extra_var.var_type = res_type;
			string temp = $1->extra_var.join_string($2->getName()+$3->extra_var.concatenator);
			$$->extra_var.concatenator = temp;
			fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
			//check for VOID
		}
		;
simple_expression : term
				  {
					  fprintf(logs,"At line no : %d simple_expression : term \n\n",line_counter);
					  $$->extra_var.concatenator = $1->extra_var.concatenator;
					  $$->extra_var.var_type = $1->extra_var.var_type;
					  fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());

				  }
		  | simple_expression ADDOP term
		  {
			  fprintf(logs,"At line no : %d simple_expression : simple_expression ADDOP term \n\n",line_counter);

			  //cout<<"$1 has = "<<$1->extra_var.concatenator<<endl;
			  string a_type = $1->extra_var.var_type;
			  string b_type = $3->extra_var.var_type;
			  string res_type  = "";

			  //type checking for operands to be added and type conversion as such
			  if((a_type=="VOID")||(b_type=="VOID"))
			  {
				  error_counter++;
			    fprintf(errors,"Error at Line %d  : Add operation with void\n\n",line_counter);
				  res_type = "INT";

			  }else if((a_type=="FLOAT")||(b_type=="FLOAT"))
			  {
						if(((a_type=="FLOAT")&&(b_type=="INT"))||((a_type=="INT")&&(b_type=="FLOAT")))
	 					 fprintf(errors,"Warning at Line %d  : Integer converted to float during Addition.\n\n",line_counter);
	 				 res_type = "FLOAT";

			  }else if((a_type=="INT")&&(b_type=="INT"))
			  {
				  res_type = "INT";
			  }

			  SymbolInfo* s = new SymbolInfo("",res_type);
			  $$ = s;
			  $$->extra_var.var_type = res_type;
			  $$->extra_var.concatenator = $1->extra_var.join_string($2->getName().append($3->extra_var.concatenator));
			  fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
		  }
		  ;
term :	unary_expression
	 {
		fprintf(logs,"At line no: %d term : unary_expression \n\n",line_counter);
		$$->extra_var.concatenator = $1->extra_var.concatenator;
		$$->extra_var.var_type = $1->extra_var.var_type;
		fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
	 }
     |  term MULOP unary_expression
	 {
		// cout<<"IN mulop"<<endl;
		 fprintf(logs,"At line no: %d term : term MULOP unary_expression \n\n",line_counter);

		 string term_type = $1->extra_var.var_type;
		 string unary_type = $3->extra_var.var_type;
		 string mult_operator = $2->getName();
		 string res_type = "";

		 map<string,int>command_map;
		 command_map["*"] = 1;
		 command_map["/"] = 2;
		 command_map["%"] = 3;

		 switch(command_map[mult_operator])
		 {
			 case 1:
			 		{
						if((term_type=="VOID")||(unary_type=="VOID"))
						{
							error_counter++;
							fprintf(errors,"Error at Line %d : Multiplication operation with void\n\n",line_counter);
							res_type = "INT";
						}
						else if((term_type=="FLOAT")||(unary_type=="FLOAT"))
						{

							if(((term_type=="FLOAT")&&(unary_type=="INT"))||((term_type=="INT")&&(unary_type=="FLOAT")))
								fprintf(errors,"Warning at Line %d : Integer converted to float during Multiplication.\n\n",line_counter);
							res_type = "FLOAT";
						}
						else if((term_type=="INT")&&(term_type=="INT"))
						{
							res_type = "INT";
						}

						SymbolInfo* s = new SymbolInfo("",res_type);
						$$ = s;
						$$->extra_var.var_type = res_type;
						$$->extra_var.concatenator = $1->extra_var.join_string($2->getName().append($3->extra_var.concatenator));
						fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
					}
			 break;
			 case 2:{
						if((term_type=="VOID")||(unary_type=="VOID"))
						{
							error_counter++;
							fprintf(errors,"Error at Line %d : Division operation with void\n\n",line_counter);
							res_type = "INT";
						}
						else if((term_type=="FLOAT")||(unary_type=="FLOAT"))
						{

							if(((term_type=="FLOAT")&&(unary_type=="INT"))||((term_type=="INT")&&(unary_type=="FLOAT")))
								fprintf(errors,"Warning at Line %d : Integer converted to float during Division.\n\n",line_counter);
							res_type = "FLOAT";
						}
						else if((term_type=="INT")&&(term_type=="INT"))
						{
							res_type = "INT";
						}

						SymbolInfo* s = new SymbolInfo("",res_type);
						$$ = s;
						$$->extra_var.var_type = res_type;
						$$->extra_var.concatenator = $1->extra_var.join_string($2->getName().append($3->extra_var.concatenator));
						fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
					}
			 break;
			 case 3:{
						if((term_type=="VOID")||(unary_type=="VOID"))
						{
							error_counter++;
							fprintf(errors,"Error at Line %d : Integer operand not on modulus operator\n\n",line_counter);
							res_type = "INT";
						}
						else if((term_type!="INT")||(unary_type!="INT"))
						{
							error_counter++;
							fprintf(errors,"Error at Line %d : Integer operand not on modulus operator\n\n",line_counter);
							res_type = "INT";
						}
						else if((term_type=="INT")&&(term_type=="INT"))
						{
							res_type = "INT";
						}

						SymbolInfo* s = new SymbolInfo("",res_type);
						$$ = s;
						$$->extra_var.var_type = res_type;
						$$->extra_var.concatenator = $1->extra_var.join_string($2->getName().append($3->extra_var.concatenator));
						fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
					}
			 break;
		 }
	 }
     ;
unary_expression : ADDOP unary_expression
				 {
					 fprintf(logs,"At line no: %d unary_expression : ADDOP unary_expression\n\n",line_counter);
					 $$->extra_var.concatenator = $1->getName().append($2->extra_var.concatenator);
					 $$->extra_var.var_type = $2->extra_var.var_type;
					 fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
					 //check for void
					 if($2->extra_var.concatenator=="VOID")
					 {
						 fprintf(errors,"Error at Line %d : Unary expression cannot be void\n\n",line_counter);
						 error_counter++;

					 }
				 }
					 | NOT unary_expression
					 {
					  fprintf(logs,"At line no: %d unary_expression : NOT unary_expression\n\n",line_counter);
					  $$->extra_var.concatenator = $1->getName().append($2->extra_var.concatenator);
						$$->extra_var.var_type = "INT";
					  fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
						//check for void
						if($2->extra_var.concatenator=="VOID")
						{
							fprintf(errors,"Error at Line %d : Unary expression cannot be void\n\n",line_counter);
							error_counter++;
						}
		 }
		 | factor
		 {
			 fprintf(logs,"At line no: %d unary_expression : factor\n\n",line_counter);
			 $$->extra_var.concatenator = $1->extra_var.concatenator;
			 $$->extra_var.var_type = $1->extra_var.var_type;
			 //fprintf(logs,"%s\n\n",$$->extra_var.var_type.c_str());
			 fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());

		 }
		 ;
factor	: variable
		{
			 fprintf(logs,"At line no: %d factor : variable\n\n",line_counter);
			 $$->extra_var.concatenator = $1->extra_var.concatenator;
			 $$->extra_var.var_type = $1->extra_var.var_type;
			 fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
		}
	| ID LPAREN argument_list RPAREN
	{

		fprintf(logs,"At line no: %d factor : ID LPAREN argument_list RPAREN\n\n",line_counter);

		$$->extra_var.concatenator = $1->getName()+m["left_first"]+$3->extra_var.concatenator+m["right_first"];
		fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());

		SymbolInfo* s = stable.LookUp($1->getName());

		if(s==0)
		{

			error_counter++;
			fprintf(errors,"Error at Line %d : Undefined or Undeclared function\n\n",line_counter);
			$3->extra_var.func_param_list.clear();

		}
		else
		{

			if(s->extra_var.ID_type=="FUNCTION")
			{
				if(s->extra_var.is_function)
				{
					//check the num of arguments matches or not
					int given_arg_list = $3->extra_var.func_param_list.size();
					int defined_arg_list = s->extra_var.func_param_list.size();

					if(given_arg_list!=defined_arg_list)
					{
						error_counter++;
						fprintf(errors,"Error at Line %d : Unequal Number of function arguments\n\n",line_counter);
						$3->extra_var.func_param_list.clear();
					}
					else
					{
						//Finally check for argument sequence of defined and called function
						for(int i=0;i<defined_arg_list;i++)
						{
							string temp1 = $3->extra_var.func_param_list[i].second;
							string temp2 = s->extra_var.func_param_list[i].second;

								if(temp1!=temp2)
								{
									error_counter++;
									fprintf(errors,"Error at Line %d : Argument Type Mismatch with function defination \n\n",line_counter);
									break;
								}

						}

						$3->extra_var.func_param_list.clear();
					}

					$$->extra_var.var_type = s->extra_var.func_ret_type; //sets the return type of the function as var type
				 $$->extra_var.ID_type = s->extra_var.ID_type;
				}
				else
				{
					error_counter++;
					fprintf(errors,"Error at Line %d :function not properly defined or declared \n\n",line_counter);
					$$->extra_var.var_type = s->extra_var.func_ret_type; //sets the return type of the function as var type
				 $$->extra_var.ID_type = s->extra_var.ID_type;
				}


			}
			else
			{
				error_counter++;
				fprintf(errors,"Error at Line %d : Function call on Non function ID\n\n",line_counter);
				$$->extra_var.var_type = "INT";
				arg_param_list.clear();
			}
		}



		}
	| LPAREN expression RPAREN
	{
		fprintf(logs,"At line no: %d factor : LPAREN expression RPAREN\n\n",line_counter);
		SymbolInfo* s = new SymbolInfo();

		string temp = m.at("left_first")+$2->extra_var.join_string(m.at("right_first"));
		s->extra_var.concatenator = temp;
		s->extra_var.var_type = $2->extra_var.var_type;
		$$=s;
		fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
	}
	| CONST_INT
	{
		fprintf(logs,"At line no: %d factor : CONST_INT\n\n",line_counter);
		$1->extra_var.var_type = "INT";
		$1->extra_var.ID_type = "CONST_INT";
		$$->extra_var.concatenator = $1->getName();
		$$->extra_var.array_index = $1->getName();
		$$->extra_var.ID_type = $1->extra_var.ID_type;
		$$->extra_var.var_type = $1->extra_var.var_type;
		fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());

	}
	| CONST_FLOAT
	{
		fprintf(logs,"At line no: %d factor : CONST_FLOAT\n\n",line_counter);
		$1->extra_var.var_type = "FLOAT";
		$1->extra_var.ID_type = "CONST_FLOAT";
		fprintf(logs,"At line no: %d factor : CONST_FLOAT\n\n",line_counter);
		$$->extra_var.concatenator = $1->getName();
		$$->extra_var.array_index = $1->getName();
		$$->extra_var.ID_type = $1->extra_var.ID_type;
		$$->extra_var.var_type = $1->extra_var.var_type;
		fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
	}
	| variable INCOP
	{
		fprintf(logs,"At line no: %d factor : variable INCOP\n\n",line_counter);
		$$->extra_var.var_type = $1->extra_var.var_type;
		$$->extra_var.concatenator = $1->getName()+$2->getName();
		fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
	}
	| variable DECOP
	{
		fprintf(logs,"At line no: %d factor : variable DECOP\n\n",line_counter);
		$$->extra_var.var_type = $1->extra_var.var_type;
		$$->extra_var.concatenator = $1->getName()+$2->getName();
		fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
	}
	;
	argument_list : arguments
							{
									fprintf(logs,"At line no: %d argument_list : arguments\n\n",line_counter);

								//so we can get variable name and type Here
									SymbolInfo* s=new SymbolInfo();
									s->extra_var.concatenator=$1->extra_var.concatenator;
									for(int i=0;i<$1->extra_var.func_param_list.size();i++)
									{
										s->extra_var.func_param_list.push_back(make_pair($1->extra_var.func_param_list[i].first,$1->extra_var.func_param_list[i].second));
									}
									$$=s;
									fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
							}
							|
							{
								SymbolInfo* s = new SymbolInfo("","");
								$$=s;
							}
			  			;

arguments : arguments COMMA logic_expression
			    {
						fprintf(logs,"At line no: %d aarguments : arguments COMMA logic_expression\n\n",line_counter);
						$$->extra_var.var_type = $1->extra_var.concatenator.append(m["comma"]+$3->extra_var.concatenator);

						string name = $3->getName();
						string variable_type = $3->extra_var.var_type;

						if($3->extra_var.var_type == "VOID")
						{
							error_counter++;
							fprintf(logs,"At line no: %d Void passed as parameter\n\n",line_counter);
						}
						else
						{
							$$->extra_var.func_param_list.push_back(make_pair(name,variable_type));
						}



						fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
					}
	      | logic_expression
				{

					fprintf(logs,"At line no: %d arguments : logic_expression\n\n",line_counter);
					//we can get VARIABLE and CONSTANT type clearly
					//cases for array passing and function passing
					//cout<<"here"<<endl;

					string name = $1->getName();
					string variable_type = $1->extra_var.var_type;
				//	cout<<"type "<<variable_type<<endl;

					if($1->extra_var.var_type == "VOID")
					{
						error_counter++;
						fprintf(logs,"At line no: %d Void passed as parameter\n\n",line_counter);
					}
					else
					{
						$$->extra_var.func_param_list.push_back(make_pair(name,variable_type));
						//control_arg++;
					}

					$$->extra_var.concatenator = $1->extra_var.concatenator;
					fprintf(logs,"%s\n\n",$$->extra_var.concatenator.c_str());
				}
	      ;
%%
int main(int argc,char *argv[])
{

	FILE* fp;

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	logs= fopen("1605079_log.txt","w");
	errors= fopen("1605079_error.txt","w");

	set_token_symbols();
	yyin=fp;
	yyparse();

  fprintf(logs,"Total Line: %d\n\n",line_counter-1);
	fprintf(logs,"Total Error: %d\n\n",error_counter);
  fprintf(errors,"Total Error: %d\n\n",error_counter);

	fclose(yyin);
  fclose(errors);
	fclose(logs);


	return 0;
}