#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;
typedef std::string::iterator iter;



class List
{   
    public:
        class Node
        {   public:
                string element;
                char behind_operator ;
                double val;
                Node()
                {
                    behind_operator = '\0';
                };
                Node(string &&TheElement,char &&b_operator)
                    :element{TheElement},behind_operator{b_operator}{}
            private:
                Node *next_node = nullptr;
                Node *previous_node = nullptr;
                friend class List;
        };
        Node *head = nullptr;
        Node *tail = nullptr;
        Node *current = nullptr;
        Node *subval = nullptr;
        int ju = -1;
        double value = 0;
        void Inputexpression();
        List(){};
        ~List(){
            Node *currentNode = head;
        while (currentNode != nullptr) {
            Node *nextNode = currentNode->next_node;
            delete currentNode;
            currentNode = nextNode;
        }
        if (sublist != nullptr) 
        {
        delete sublist;
        }
        };
        string readstr;
        void readin(string str) 
        {
            cout << "请输入运算表达式:" << endl;
            getline(cin , readstr);
        }
        void run();
        
        void judge(string str)
        {   try{
            first_judge(readstr);
            second_judge(readstr);
            third_judge(readstr);
            forth_judge(readstr);
            fifth_judge(readstr);
            }catch(string msg)
            {
                cout << msg << endl;
                exit(1);
            }
            
        };
        double calculate()
        {
            readin(readstr);
            judge(readstr);
            try{
                vector<string> data = transforinto_postfix(readstr);
                return calculate_postfix(data);
            }catch(const char *msg)
            {
                 cout << msg << endl;
                        exit(1);
            }
        };
        bool judge_element(iter it)
        {
            return *it == 'e'||'0' <= *it && *it <= '9'||*it=='.';
        };
        bool judge_operator(iter it)
        {
            return *it == '+' || *it == '-' || *it == '*' || *it == '/';
        };
//try{
//            Inputexpression();}catch(const char *msg)
//            {
//                cout << msg << endl;
//                exit(1);
//            }
//            try{
//            transfor();}catch(const char *msg)
//            {
//                cout << msg << endl;
//                exit(1);
//            }
//            try{
//            run();}catch(const char *msg)
//            {
//                cout << msg << endl;
//                exit(1);
//            }
//            return value;
private:
        int acquire_prefrence(char op);
        vector<string> transforinto_postfix(const string expression);
        double calculate_postfix(const vector<string> data);
        double operation(double &a,char opera,double &b);
        void first_judge(string str);
        void second_judge(string str);
        void third_judge(string str);
        void forth_judge(string str);
        void fifth_judge(string str);
        void behind_copy(iter subend , iter end , Node *&subval);
        void front_copy(iter begin , iter subbegin , Node *&subval);
        List *sublist = nullptr;
        void copy(iter begin , iter subbegin, iter subend , iter end);
        void copy(iter begin , iter end);
        iter  bsub = readstr.end();
        iter  esub = readstr.end();
        iter  begread = readstr.begin();
        iter  endread = readstr.end();
        bool judge_element(char it);
        bool judge_number(char it);
        bool judge_operator(char it);
        string substr(string str,iter begin,iter end);
        void transfor();
        int which_kind_of_copy = 0;
        int is_sublist_copy = 0;
        void myjudge()
        {
            for(auto i = head;i!=nullptr;i=i->next_node)
            {
                cout<<i->element<<' ';
            }
        }
};
int List::acquire_prefrence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
};
double List::operation(double &a,char opera,double &b)
        {
            switch(opera)
            {
                case '+': return a+b;
                case '-': return a-b;
                case '*': return a*b;
                case '/': if(b == 0)
                {  try{
                    throw "A divisor of 0 is ILLEGAL";
                }catch(const char *msg)
                    {
                        cout << msg << endl;
                        exit(1);
                    }
                }
            return a / b;
                default: throw "ILLEGAL OPERATION";
            }
        };
bool List::judge_element(char it)
    {
        return it == 'e'||'0' <= it && it <= '9'||it=='.'||it =='E';
    };
bool List::judge_number(char it)
    {
        return '0' <= it && it <= '9';
    };
bool List::judge_operator(char it)
    {
        return it == '+' || it == '-' || it == '*' || it == '/';
    };
vector<string> List::transforinto_postfix(const string expression) {
    stack<char> opStack;
    vector<string> output;
    int i = 0;
    int len = expression.length();
while (i < len) {
        if (expression[i]==' ') {
            ++i;
            continue;
        }
        if (judge_element(expression[i])) {
            string number;
            while (i < len && (judge_element(expression[i]))) {
                if (expression[i] == '.') {
                    number += expression[i];
                    ++i;
                }
                else if (expression[i] == 'e' || expression[i] == 'E') {
                    number += expression[i];
                    ++i;
                    if (i < len && (expression[i] == '+' || expression[i] == '-')) {
                        number += expression[i];
                        ++i;
                    }
                }
                else {
                    number += expression[i];
                    ++i;
                }
            }
            output.push_back(number);
            continue;
        }
        if (expression[i] == '-' && (i == 0 || expression[i-1] == '(' || judge_operator(expression[i-1]))) {
            string number = "-";
            i++;
            while (i < len && (judge_element(expression[i]))) {
               if (expression[i] == '.') {
                    number += expression[i];
                    ++i;
                }
                else if (expression[i] == 'e' || expression[i] == 'E') {
                    number += expression[i];
                    ++i;
                    if (i < len && (expression[i] == '+' || expression[i] == '-')) {
                        number += expression[i];
                        ++i;
                    }
                    if (i >= len || !judge_number(expression[i])) {
                        throw "ILLEAGAL OPERATION";
                    }
                }
                else {
                    number += expression[i];
                    ++i;
                }
            }
            output.push_back(number);
            continue;
        }
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') 
        {
            opStack.push(expression[i]);
            ++i;
            continue;
        }
        if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') 
        {
            char expected;
            if (expression[i] == ')') expected = '(';
            else if (expression[i] == ']') expected = '[';
            else expected = '{';
            while (!opStack.empty() && opStack.top() != expected) {
                output.push_back(string(1, opStack.top()));
                opStack.pop();
            }

            if (opStack.empty()) {
                throw "ILLEGAL PARENTHESIS MATCHING";
            }
            opStack.pop();
            i++;
            continue;
        }

        if (judge_operator(expression[i])) 
        {
            char currentOp = expression[i];
            while (!opStack.empty() && judge_operator(opStack.top()) &&
                   acquire_prefrence(opStack.top()) >= acquire_prefrence(currentOp)) {
                output.push_back(string(1, opStack.top()));
                opStack.pop();
            }
            opStack.push(currentOp);
            i++;
            continue;
        }
    }

    while (!opStack.empty()) 
    {
        char topOp = opStack.top();
        opStack.pop();
        if (topOp == '(' || topOp == '[' || topOp == '{' ||
            topOp == ')' || topOp == ']' || topOp == '}') {
            throw "ILLEGAL PARENTHESIS MATCHING";
        }
        output.push_back(string(1, topOp));
    }

    return output;
}

double List::calculate_postfix(const vector<string> data) 
{
    stack<double> calculate_stack;
    for (const auto& expression : data) {
        if (expression.length() == 1 && judge_operator(expression[0])) 
        {
            double b = calculate_stack.top(); 
            calculate_stack.pop();
            double a = calculate_stack.top(); 
            calculate_stack.pop();
            double result = operation(a,expression[0],b);
            calculate_stack.push(result);
        }
        else {
            try {
                double num = std::stod(expression);
                calculate_stack.push(num);
            }
            catch (const invalid_argument&) {
                throw "ILLEGAL OPERATION";
            }
        }
        
    }
    return calculate_stack.top();
}
void List::first_judge (string str)
{
     for(auto it = readstr.begin(); it != readstr.end(); ++it)
    {
        if(judge_element(*it)||judge_operator(*it)||*it == '('||*it == ')'||*it == '['||*it == ']'||*it == '{'||*it == '}'){}    
        else
            {
                string msg = "ILLEGAL CHARACTER ";
                msg += *it;
                throw msg;
            }
    }
}
void List::second_judge(string str)
{   
    int judge = 0;
    for(auto it = readstr.begin(); it != readstr.end(); ++it)
    {   
        if(*it == '(' || *it == ')'|| *it == '[' || *it == ']' || *it == '{' || *it == '}' || judge_number(*it))
            judge = 0;
        if(judge_operator(it))
        {  
                if(judge == 1)
            {  
                string msg;
                msg = "ILLEGAL OPERATION";
                throw msg;
            }
            judge = 1;
        if(*(it+1) == '-' && (it+1) != readstr.end())
                ++it;
        }
    }
}
void List::third_judge(string str)
{
    int lilbe = 0, lilen = 0, mebe = 0, meen = 0, bigbe = 0, bigen = 0;
    for(auto it = readstr.begin(); it != readstr.end(); ++it)
    {
        if(*it == '(')
            ++lilbe;
        if(*it == ')')
            ++lilen;
        if(*it == '[')
            ++mebe;
        if(*it == ']')
            ++meen;
        if(*it == '{')
            ++bigbe;
        if(*it == '}')
            ++bigen;
    }
    if(lilbe != lilen || mebe != meen || bigbe != bigen)
        {   
            string msg =  "ILLEGAL PARENTHESIS MATCHING";
            throw msg;
        }
}
void List::forth_judge(string str)
{
    int judge = 0;
    for(auto it = readstr.begin(); it != readstr.end(); ++it)
    {   
        if(judge_operator(it))
        {
            if(!(judge_element(it+1))&&*(it+1)!='-'&&*(it+1)!='('&&*(it+1)!='['&&*(it+1)!='{')
            { 
                string msg = "ILLEGAL OPERATION";
                throw msg ;
            }
        }
    }
    for(auto it = readstr.begin(); it != readstr.end(); ++it)
    {
        if(*it == '.'||*it == 'e'||*it == 'E')
        {
            if(judge_number(*(it-1)) && judge_number(*(it+1)))
                continue;
            else
            {  
                string msg = "ILLEGAL OPERATION";
                throw msg;
            }
        }
    }
}
void List::fifth_judge(string str)
{   bool judge_point = false;
    int judge_e = false;
     for(auto it = readstr.begin(); it != readstr.end(); ++it)
    {   
        if(judge_operator(it))
        {
            judge_e = false;
            judge_point = false;
        }
        if(*it == 'e'||*it == 'E')
        {   if(judge_e == true)
            {  
                string msg = "ILLEGAL OPERATION";
                throw msg;
            }
            judge_e = true;
        }
        if(*it == '.')
        {   if(judge_point == true)
             {  
                string msg = "ILLEGAL OPERATION";
                throw msg;
            }
            judge_point = true;
        }
    }
}
void List::behind_copy(iter subend , iter end , Node *&subval ) //注意parent量都不包含括号，sub带括号
{           
            if(subend + 1 == end)
                return;
            iter it = subend;
            ++it;
            subval->behind_operator = *it;
            current = new Node;
            Node *before = subval;
            subval->next_node = current;
            current->previous_node = subval;
            ++it;
            current->element += *it;
            before = current;
            ++it;
            if(which_kind_of_copy == 0)
                head = subval;
            while(it != end)
            {   
                if(judge_operator(it) )
                {   
                    if(judge_operator(it-1))
                        {
                            if(*it == '-')
                        { 
                            current->element += *it;
                        }
                        }
                    else{
                    current = new Node;
                    before->next_node = current;
                    current->previous_node = before;
                    before->behind_operator = *it;
                    before = current;
                    }
                }
                if(judge_element(it))
                {   
                    current->element += *it;
                    if(*it == 'e')
                {
                    if(*(it+1)=='-'||*(it+1)=='+'){
                        current->element += *(++it);
                        continue;
                    }
                }
                }
                ++it;
            }
            tail = current;
}
void List::front_copy(iter begin , iter subbegin,Node *&subval)//注意parent量都不包含括号，sub带括号
{           
            if(begin + 1 == subbegin)
            {
                return;
            }
            iter it = begin;
            Node *first = new Node;
            Node *before = first;
            current = first;
            current->element += *it;
            ++it;
            while(it + 1  != subbegin)
            {
                if(judge_element(it))
                { 
                    current->element += *it;
                    if(*it == 'e')
                {
                    if(*(it+1)=='-'||*(it+1)=='+'){
                        current->element += *(++it);
                        continue;
                    }
                }
                }
                   if(judge_operator(it))
                { 
                    if(judge_operator(it-1))
                    {
                        if(*it == '-')
                        {
                            current->element += *it;
                        }
                    }
                    else{
                    current = new Node;
                    current->previous_node = before;
                    before->behind_operator = *it;
                    before->next_node = current;
                    before = current;
                    }
                }
                ++it;
            }
            before->behind_operator = *it;
            current = subval;
            current->previous_node = before;
            before->next_node = current;
            head = first;
            if(which_kind_of_copy == 1)
                return;
            tail = current;
}

void List::copy(iter begin , iter end)
{   if(begin == end)
        return;
    current = new Node;
    head = current;
    current->element += *begin;
    Node* before = current;
    for(auto it = begin+1; it != end ; ++it)
    {   
        if(judge_element(it))
        {
            current->element += *it;
            if(*it == 'e')
                {
                    if(*(it+1)=='-'||*(it+1)=='+'){
                        current->element += *(++it);
                        continue;
                    }
                }
        }
        if(judge_operator(it))
        {   
            if(judge_operator(it-1))
                {
                    if(*it == '-')
                    {
                        current->element += *it;
                    }
                }
            else{
            current = new Node;
            current->previous_node = before;
            before->behind_operator = *it;
            before->next_node = current;
            before = current;}
        }
    }
        tail = current;
}

void List::copy( iter begin , iter subbegin, iter subend , iter end)
{ 
    if( begin == subbegin )
    {
        if( subend == end)
            value = sublist->value;
        else 
        {   subval = new Node;
            subval->val = sublist->value;
            behind_copy(subend,end,subval);
        }
    }
    else
    {
        if(subend == end)
        {   subval = new Node;
            subval->val = sublist->value;
            front_copy(begin,subbegin,subval);
        }
        else
        {
            subval = new Node;
            subval->val = sublist->value;
            which_kind_of_copy = 1;
            front_copy(begin,subbegin,subval);
            behind_copy(subend,end,subval);
            which_kind_of_copy = 0;
        }
    }
}
string List::substr(string str,iter begin,iter end)
{
    string  strs ;
    if(begin == end)
        return "";
    for(auto i = begin+1;i != end;++i)
    {
        strs += *i;
    }
    return strs;
}


void List::Inputexpression()
{
    begread = readstr.begin();
    endread = readstr.end();
    for(auto it = readstr.begin(); it != readstr.end(); ++it)
    {
        if( *it == '(' || *it == '[' || *it == '{')
    {   
        switch(*it)
        {
            case('('):ju = 0; break;
            case('['):ju = 1; break;
            case('{'):ju = 2;break;
        }
        iter temb = it;
        List *subList = new List;
        sublist = subList;
        auto i = readstr.end();
        while(*i != ')'  && i != temb && *i != ']' && *i != '}')
        {
            --i;
        }
        if((*i == ')'&& ju == 0)||(*i == ']'&& ju == 1)||(*i == '}'&& ju == 2));
        else throw "ILLEGAL PARENTHESIS MATCHING";
        iter teme = i;
        sublist->begread = bsub = temb;
        sublist->endread = esub = teme;
        is_sublist_copy = 1;
        sublist->readstr = substr(readstr,sublist->begread,sublist->endread);
        if(sublist->readstr == "")
            break;
        subList->Inputexpression();
        break;
    }   
    }
    if(is_sublist_copy == 1)
        copy(begread,bsub,esub,endread);
    else
        copy(begread,endread);
}

void List::transfor()
{   
    for(auto i = head ;i != nullptr ;i = i->next_node)
    {   if(i == subval);
        else{
        i->val = stod(i->element);
        }
    }
    if(sublist == nullptr)
        return;
    sublist->transfor();
}
void List::run()
{   
    if(sublist != nullptr)
    {   
        sublist->run();
        subval->val = sublist->value;
    }
    for(auto i = head;i != nullptr ;)
    {   
        if(i->behind_operator == '*'||i->behind_operator == '/')
        {   
            auto next = i->next_node;
            i->behind_operator = next->behind_operator;
            i->next_node = next->next_node;
        }
        else
        i = i->next_node;
    }
    for(auto i = head;i != nullptr ; )
    {
        if(i->behind_operator == '+'||i->behind_operator == '-')
        {   
            auto next = i->next_node;
            i->behind_operator = next->behind_operator;
            i->next_node = next->next_node;
        }
        else
        i = i->next_node;
    }
    value = head->val; 
}
