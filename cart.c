#define _CRT_SECURE_NO_WARNINGS
// cart.c
#include <stdio.h>
#include "cart.h"

void add_to_cart(CartItem* cart, int* cart_count, Product* products, int product_index, int quantity) {
    if (product_index < 0 || product_index >= MAX_PRODUCTS) {
        printf("Invalid product index.\n");
        return;
    }
    if (*cart_count < 0 || *cart_count >= MAX_PRODUCTS) {
        printf("Invalid cart count.\n");
        return;
    }
    if (quantity <= 0) {
        printf("Invalid quantity.\n");
        return;
    }
    if (products[product_index].stock < quantity) {
        printf("Not enough stock available.\n");
        return;
    }

    CartItem new_item;
    new_item.id = *cart_count + 1;
    new_item.product_id = products[product_index].id;
    new_item.quantity = quantity;

    cart[*cart_count] = new_item;
    (*cart_count)++;

    products[product_index].stock -= quantity;
    printf("Product added to cart successfully.\n");
}

void view_cart(const CartItem* cart, int cart_count, const Product* products) {
    printf("Cart Contents:\n");
    for (int i = 0; i < cart_count; i++) {
        int product_index = cart[i].product_id - 1;
        if (product_index >= 0 && product_index < MAX_PRODUCTS) {
            printf("Item ID: %d\n", cart[i].id);
            printf("Product Name: %s\n", products[product_index].name);
            printf("Quantity: %d\n", cart[i].quantity);
            printf("----------\n");
        }
    }
}
