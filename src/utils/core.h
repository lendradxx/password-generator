#ifndef CORE_H
#define CORE_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void visitUrl(char* url) {
    gtk_show_uri_on_window(NULL, url, time(0), NULL);
}

int randomNumber(int minimum, int maximum) {
    return (rand() % (maximum - minimum)) + 1;
}

void randomOrders(int length, char* list, char* dest) {
    srand(time(NULL));
    char* c = malloc(1);
    for (int i = 0; i <= length; i++) {
        sprintf(c, "%c\0", list[randomNumber(0, strlen(list))]);
        strcat(dest, c);
    }

    free(c);
}

void generatePassword(int length, bool numberOption, bool symbolOption, char* dest) {
    char* lists;
    char *result = malloc(length * sizeof(char*));
    if (!numberOption) {
        length = (int)length/2;
        lists = "abcdefhijklmnopqrstuvwxyzABCDEFHIJKLMNOPQRSTUVWXYZ!@#$^&*";
    } else if (!symbolOption) {
        length = (int)length/2;
        lists = "abcdefhijklmnopqrstuvwxyzABCDEFHIJKLMNOPQRSTUVWXYZ123456890";
    } else {
        length = (int)length/3;
        lists = "abcdefhijklmnopqrstuvwxyzABCDEFHIJKLMNOPQRSTUVWXYZ!@#$^&*1234567890";
    }

    randomOrders(length, lists, result);
    sprintf(dest, "%s", result);
    free(result);
}

void copyToClipboard(char* text) {
    GtkClipboard* clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    gtk_clipboard_set_text(clipboard, text, strlen(text));
}

#endif