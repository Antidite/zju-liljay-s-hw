# zju-liljay-s-hw
1.我在判断iterator以及const_iterator的默认构造函数是否为空时引入了is_null 判断函数。
2.在erase(iterator from ,iterator to)函数中一个个删除节点的方法可以有所优化，即删除一段范围的代码如下。
iterator erase(iterator from, iterator to)  
{  
  if (from == to) 
  return to;  
  
  Node* start = from.current;  
  Node* end = to.current;  
  
  start->prev->next = end;  
  end->prev = start->prev;  
  
  while (from != to) {  
        Node* delenode = from.current;  
        from++;  
        delete delenode;  
        theSize--;  
    }  
  
  return to;  
} 
我用备注格式放在List.h头文件里
