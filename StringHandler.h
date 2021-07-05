#ifndef COMPILER_STRINGHANDLER_H
#define COMPILER_STRINGHANDLER_H


int tempCount = 0, labelCount = 0;

std::string stringAdder(int count, ...){
	va_list varStringList;
	int counter;
	const char* t;
	std::string s;
	va_start(varStringList, count);
	for(int counter=0;counter<count;counter++){
		t = va_arg(varStringList, const char*);
		std::string temp(t);
		s += temp;
	}
	va_end(varStringList);
	return s;
}

/* ******************* */
/*    New Temporary    */
/* 		  Label        */
/*     Generator       */
/* ******************* */
char* newLabel(){
	char* newLabel = new char[4];
	strcpy(newLabel, "L");
	char newLabelCounter[3];
	sprintf(newLabelCounter, "%d", labelCount);
	labelCount++;
	strcat(newLabel, newLabelCounter);
	return newLabel;
}

/* ******************* */
/*    New Temporary    */
/* 		Variable       */
/*     Generator       */
/* ******************* */
char* newTemp(){
	char* tempVar = new char[4];
	strcpy(tempVar, "t");
	char tempVarCounter[3];
	sprintf(tempVarCounter, "%d", tempCount);
	tempCount++;
	strcat(tempVar, tempVarCounter);
	return tempVar; 
}

std::vector<std::string> split_string(const std::string& str,const std::string& delimiter){
    std::vector<std::string> splitted;

    std::string::size_type pos = 0;
    std::string::size_type prev = 0;

    while ((pos = str.find(delimiter, prev)) != std::string::npos){
        splitted.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }
    splitted.push_back(str.substr(prev));

    return splitted;
}

bool is_valid_string(std::string a, std::string b){
    int a_indx = a.find("MOV");
    int b_indx = b.find("MOV");

    if((a_indx!=std::string::npos)&&(b_indx!=std::string::npos)){
        if((a.find(",")!=std::string::npos)&&(b.find(",")!=std::string::npos)){
            return true;
        }
    }
    return false;
}

/*returns an optimized version of the assembly code*/
std::string optimizer(std::string code)
{

    std::string result;
    int i;
    bool is_it_last = false;
    int temp;

    std::vector<std::string>vect1;
    std::vector<std::string>vect2;

    /*we get the splitted code*/
    std::vector<std::string>splitted_code =split_string(code,"\n");

     //removing all the extra newlines from the splitted string
    for(int i=0;i<splitted_code.size();i++)
    {
        if(splitted_code[i]!="")
        {
            vect1.push_back(splitted_code[i]);
		}
	}

	splitted_code.clear();

	for(int i=0;i<vect1.size();i++)
	{
		splitted_code.push_back(vect1[i]);
	}

	vect1.clear();

		/*this portion checks if a pair of string is valid for comparison and then if we can find our required condition, we skip
		over one concatenation of the result string, thus giving us an optimized string*/

    for( i=0;i<splitted_code.size();i++)
    {
        temp = i;

        if(i!=splitted_code.size()-1){
            if(is_valid_string(splitted_code[i],splitted_code[i+1])){
                std::string temp1 = splitted_code[i].substr(splitted_code[i].find(" ")+1,splitted_code[i].length()-1);
                std::string temp2 = splitted_code[i+1].substr(splitted_code[i+1].find(" ")+1,splitted_code[i].length()-1);

                vect1 = split_string(temp1,",");
                vect2 = split_string(temp2,",");

                if((vect1[0]==vect2[1])&&(vect1[1]==vect2[0])){
                    i++;
                }

                if((temp+1)==splitted_code.size()){
                    is_it_last = true;
                }
            }
        }

        if(!is_it_last){
            result += splitted_code[temp]+"\n";
        }
        else{
            is_it_last = false;
        }
    }
    return result;
}

#endif