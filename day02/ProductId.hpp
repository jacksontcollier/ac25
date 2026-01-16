#ifndef __PRODUCT_ID_HPP__
#define __PRODUCT_ID_HPP__

class ProductId
{
public:
    unsigned long id;
    ProductId(unsigned long product_id) : id(product_id) {};
    bool is_invalid();
    bool is_invalid_p2();
};

#endif
