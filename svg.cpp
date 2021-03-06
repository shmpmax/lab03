#include <iostream>
#include <vector>
#include "svg.h"
#include <string>
using namespace std;


void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}


void svg_end()
{
    cout << "</svg>\n";
}


void svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>\n";
}


void svg_rect(double x, double y, double width, double height) {
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' />\n";
}

void svg_blockwidth(double& BLOCK_WIDTH, bool& block)
{
    if (BLOCK_WIDTH < 3 || BLOCK_WIDTH > 30)
    {
        block = true;
    }
    else
    {
        block = false;
    }
}

void show_histogram_svg(const vector<size_t>& bins)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    double BLOCK_WIDTH;
    size_t max_count = bins[0];
    for (size_t bin : bins)
    {
        if (max_count < bin)
        {
            max_count = bin;
        }
    }

    cerr << "Enter BLOCK_WIDTH : ";
    cin >> BLOCK_WIDTH;
    bool block = true;
    while (block == true)
    {
        svg_blockwidth(BLOCK_WIDTH, block);
        if (block == true)
        {
            cerr << "Limit! Re enter BLOCK_WIDTH : ";
            cin >> BLOCK_WIDTH;
        }
    }


    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    for (size_t i = 0; i < bins.size(); i++) {
        size_t height = bins[i] * BLOCK_WIDTH;
        if (max_count * BLOCK_WIDTH > IMAGE_WIDTH - TEXT_WIDTH)
        {
            height = (IMAGE_WIDTH - TEXT_WIDTH) * (static_cast<double>(bins[i]) / max_count);
        }
        const double bin_width = height;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bins[i]));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT);
        top += BIN_HEIGHT;
    }
    svg_end();
}