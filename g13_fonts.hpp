//
// Created by khampf on 07-05-2020.
//

#ifndef G13_G13_FONTS_HPP
#define G13_G13_FONTS_HPP

#include <memory>
#include <cstring>

namespace G13 {
    class G13_Font;

    typedef std::shared_ptr<G13_Font> FontPtr;

    class G13_FontChar {
    public:
        static const int CHAR_BUF_SIZE = 8;
        enum FONT_FLAGS { FF_ROTATE = 0x01 };

        G13_FontChar() {
            memset(bits_regular, 0, CHAR_BUF_SIZE);
            memset(bits_inverted, 0, CHAR_BUF_SIZE);
        }
        void set_character(unsigned char* data, int width, unsigned flags);
        unsigned char bits_regular[CHAR_BUF_SIZE]{};
        unsigned char bits_inverted[CHAR_BUF_SIZE]{};
    };

    class G13_Font {
    public:
        G13_Font();
        explicit G13_Font(const std::string& name, unsigned int width = 8);

        // void set_character(unsigned int c, unsigned char* data);

        template <class ARRAY_T, class FLAGST>
        void install_font(ARRAY_T& data, FLAGST flags, int first = 0);

        [[nodiscard]] const std::string& name() const { return _name; }
        [[nodiscard]] unsigned int width() const { return _width; }

        const G13_FontChar& char_data(unsigned int x) { return _chars[x]; }

    protected:
        std::string _name;
        unsigned int _width;

        G13_FontChar _chars[256];

        // unsigned char font_basic[256][8];
        // unsigned char font_inverted[256][8];
    };

}
#endif //G13_G13_FONTS_HPP