// Shared data types for ASCII Camera project

#include <vector>
#include <cstdint>

// Raw camera frame from capture
struct RawFrame {
    std::vector<uint8_t> data;
    int width;
    int height;
    int channels;  // 3 for RGB, 1 for grayscale, 4 for RGBA
    
    RawFrame() : width(0), height(0), channels(0) {}
    
    RawFrame(int w, int h, int c) 
        : width(w), height(h), channels(c) {
        data.resize(w * h * c);
    }
    
    size_t size() const {
        return data.size();
    }
};

// Single ASCII character cell
struct AsciiCell {
    char character;        // ASCII character (' ' to '@')
    uint8_t brightness;   // 0-255 brightness value
    
    AsciiCell() : character(' '), brightness(0) {}
    AsciiCell(char c, uint8_t b) : character(c), brightness(b) {}
};

// Grid of ASCII cells for rendering
struct AsciiGrid {
    std::vector<AsciiCell> cells;
    int width;
    int height;
    
    AsciiGrid() : width(0), height(0) {}
    
    AsciiGrid(int w, int h) : width(w), height(h) {
        cells.resize(w * h);
    }
    
    size_t size() const {
        return cells.size();
    }
    
    AsciiCell& at(int x, int y) {
        return cells[y * width + x];
    }
};

