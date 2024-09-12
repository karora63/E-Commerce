
#define _CRT_SECURE_NO_WARNINGS
// product.c
#include <stdio.h>
#include <string.h>
#include "product.h"

void add_product(Product* products, int* product_count) {
    if (*product_count >= MAX_PRODUCTS) {
        printf("Product limit reached.\n");
        return;
    }

    Product new_product;
    new_product.id = *product_count + 1;

    printf("Enter product name: ");
    fgets(new_product.name, sizeof(new_product.name), stdin);
    // Remove newline character if present
    new_product.name[strcspn(new_product.name, "\n")] = '\0';

    printf("Enter product price: ");
    scanf("%lf", &new_product.price);

    printf("Enter product stock quantity: ");
    scanf("%d", &new_product.stock);
    // Clear the input buffer
    while (getchar() != '\n');

    products[*product_count] = new_product;
    (*product_count)++;
    printf("Product added successfully.\n");
}

void list_products(const Product* products, int product_count) {
    printf("List of Products:\n");
    for (int i = 0; i < product_count; i++) {
        printf("ID: %d\n", products[i].id);
        printf("Name: %s\n", products[i].name);
        printf("Price: %.2f\n", products[i].price);
        printf("Stock: %d\n", products[i].stock);
        printf("----------\n");
    }
}
