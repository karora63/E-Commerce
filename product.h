// product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[100];
    double price;
    int stock;
} Product;

void add_product(Product* products, int* product_count);
void list_products(const Product* products, int product_count);

#endif // PRODUCT_H

