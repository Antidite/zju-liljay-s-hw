double calculates = 0.0;
    List * user = new List;
    calculates = user->calculate();
    std::cout <<"答案是：" << calculates << std::endl; 
    delete user;
    return 0;