#include <string>
#include <string_view>


// mixins are small classes that can be inherited from to add functionality
struct Point2D {
    int x;
    int y;
};


class Box { // mixin Box class
private:
    Point2D m_top_left {};
    Point2D m_bottom_right {};

public:
    void set_top_left(Point2D point) {
        m_top_left = point;
    }

    void set_bottom_right(Point2D point) {
        m_bottom_right = point;
    }
};


class Label { // mixin Label class
private:
    std::string m_text {};
    int m_font_size {};

public:
    void set_text(const std::string_view str) {
        m_text = str;
    }

    void set_font_size(int font_size) {
        m_font_size = font_size;
    }
};


class Button: public Box, public Label {};


int main() {
    Button button {};

    button.set_top_left({1, 1});
    button.set_bottom_right({10, 10});
    button.set_text("Username: ");
    button.set_font_size(6);

    return 0;
}
