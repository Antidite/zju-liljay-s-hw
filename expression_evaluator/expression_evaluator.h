#include<iostream>
#include<string>
#include<limits>
#include <cstdlib>
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
            delete sublist;
        };
        string readstr;
        void readin(string str) 
        {
            cout << "请输入运算表达式:" << endl;
            getline(cin , readstr);
        }
        void run();
        double operation(double &a,char opera,double &b)
        {
            switch(opera)
            {
                case '+': return add(a,b);
                case '-': return minus(a,b);
                case '*': return times(a,b);
                case '/': return divide(a,b);
            }
        };
        double add(double &a,double &b)
        {
            return a + b;
        };
        double minus(double &a,double &b)
        {
            return a - b;
        };
        double times(double &a,double &b)
        {
            return a * b;
        };
        double divide(double &a,double &b)
        {  
            if(b == 0)
                {  try{
                    throw "A divisor of 0 is ILLEGAL";
                }catch(const char *msg)
                    {
                        cout << msg << endl;
                        exit(1);
                    }
                }
            return a / b;
        };
        void judge(string str)
        {   try{
            first_judge(readstr);
            second_judge(readstr);
            third_judge(readstr);
            }catch(const char *msg)
            {
                cout << msg << endl;
                exit(1);
            }
            
        };
        double calculate()
        {
            readin(readstr);
            judge(readstr);
            Inputexpression();
            transfor();
            run();
            return value;
        };
private:
        void first_judge(string str);
        void second_judge(string str);
        void third_judge(string str);
        void behind_copy(iter subend , iter end , Node *&subval);
        void front_copy(iter begin , iter subbegin , Node *&subval);
        List *sublist = nullptr;
        void copy(iter begin , iter subbegin, iter subend , iter end);
        void copy(iter begin , iter end);
        iter  bsub = readstr.end();
        iter  esub = readstr.end();
        iter  begread = readstr.begin();
        iter  endread = readstr.end();
        string substr(string str,iter begin,iter end);
        void transfor();
        int which_kind_of_copy = 0;
        int is_sublist_copy = 0;
        bool judge_element(iter it)
        {
            return *it == 'e'||'0' <= *it && *it <= '9'||*it=='.';
        };
        bool judge_operator(iter it)
        {
            return *it == '+' || *it == '-' || *it == '*' || *it == '/';
        };
};
void List::first_judge (string str)
{
     for(auto it = readstr.begin(); it != readstr.end(); ++it)
    {
        if(*it == 'e'||*it == '+' || *it == '-' || *it == '*' || *it == '/' || *it == '(' || *it == ')'|| *it == '[' || *it == ']' || *it == '{' || *it == '}' || ('0' <= *it && *it <= '9'||*it=='.')){}    
        else
            {
            throw "ILLEGAL CHARACTER";
            }
    }
}
void List::second_judge(string str)
{   
    int judge = 0;
    for(auto it = readstr.begin(); it != readstr.end(); ++it)
    {   
        if(*it == '(' || *it == ')'|| *it == '[' || *it == ']' || *it == '{' || *it == '}' || ('0' <= *it && *it <= '9'))
            judge = 0;
        if(judge_operator(it))
        {  
                if(judge == 1)
            {
                throw "ILLEGAL OPERATION";
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
            throw "ILLEGAL PARENTHESIS MATCHING";
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
        while(!(*i == ')' && ju == 0) && i != temb && !(*i == ']' && ju == 1)&& !(*i == '}'&& ju == 2))
        {
            --i;
        }
        if(i == temb)
            {
            throw "ILLEGAL PARENTHESIS MATCHING";
            }
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
            i->val = i->behind_operator == '*'?  times(i->val,next->val):divide(i->val,next->val);
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
            i->val = i->behind_operator == '+'?  add(i->val,next->val):minus(i->val,next->val);
            i->behind_operator = next->behind_operator;
            i->next_node = next->next_node;
        }
        else
        i = i->next_node;
    }
    value = head->val; 
}