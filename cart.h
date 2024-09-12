// cart.h
#ifndef CART_H
#define CART_H

#include "product.h"

typedef struct {
    int id;
    int product_id;
    int quantity;
} CartItem;

void add_to_cart(CartItem* cart, int* cart_count, Product* products, int product_index, int quantity);
void view_cart(const CartItem* cart, int cart_count, const Product* products);

#endif // CART_H
