#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;
using big_dec = vector<unsigned int>;
using big_hex = vector<unsigned int>;

big_dec hex2dec(const big_hex &in) {
    big_hex hex_num(in.begin(), in.end());
    big_dec dec_num;
    bool all_zero_q = false;
    
    while (!all_zero_q) {
        all_zero_q = true;
        for (int i = hex_num.size() - 1; i >= 0; --i) {
            int q = hex_num[i] / 10;
            int r = hex_num[i] % 10;
            hex_num[i] = q;
            if (i > 0) {
                hex_num[i - 1] += (r << 8);
            } else {
                //dec_num.insert(dec_num.begin(), r);
                dec_num.push_back(r);
            }
            all_zero_q &= (q == 0);
        }
    }
    return dec_num;
}

void show_big_nums(const big_hex& hex_num, const big_dec& dec_num) {
    cout << "Heximal number = 0x";
    for (int i = hex_num.size() - 1; i >= 0; --i) cout << setfill('0') << setw(2) << right << hex << hex_num[i];
    cout << endl;

    cout << "Decimal number = ";
    for (int i = dec_num.size() -1; i >= 0; --i) cout << dec_num[i];
    cout << endl;
}

int main(void) {
    vector<big_hex> hex_numbers {
        {0x02, 0x01}, // 0x102
        {0xff, 0xff, 0xff, 0xff}, // 0xffffffff
        {0x0, 0x0, 0x0, 0x1}, // 0x1000000
        {0x44, 0x33, 0x22, 0x11}, // 0x11223344
        {0x9a},
    };

    for (const auto& hex_num : hex_numbers) {
        big_dec dec_num = hex2dec(hex_num);
        show_big_nums(hex_num, dec_num);
    }
    return 0;
}
