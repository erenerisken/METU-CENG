#include <iostream>

#include "tpbst.hpp"

int main() {
    TwoPhaseBST<int> tpbst;

    tpbst.print()
            .insert("ceng351", "sec2", 0)
            .insert("ceng351", "sec1", 0)
            .insert("ceng351", "sec3", 0)
            .insert("ceng351", "sec4", 0)
            .insert("ceng213", "sec1", 5)
         //   .remove("ceng213", "sec1")
            .insert("ceng435", "sec1", 5)
            .insert("ceng435", "sec2", 5)
            .insert("ceng435", "sec4", 5)
            .insert("ceng435", "sec3", 5)
            .insert("ceng000", "sec3", 5)
            .insert("ceng000", "sec4", 5)
            .insert("ceng000", "sec1", 5)
            .insert("ceng000", "sec2", 5)
            .insert("ceng453", "sec1", 5)
			.print();

    return 0;
}
