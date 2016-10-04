#include "otfread.h"
#include "otfdata.h"
#include <iostream>
#include <fstream>

namespace otfread
{
    uint8_t swap_byte_(uint8_t data)
    {
        return data;
    }
    uint16_t swap_byte_(uint16_t data)
    {
        return static_cast<uint16_t>((data << 8) | (data >> 8));
    }
    uint32_t swap_byte_(uint32_t data)
    {
        return (swap_byte_(static_cast<uint16_t>(data & 0xffff)) << 16) |
               (swap_byte_(static_cast<uint16_t>((data >> 16) & 0xffff)));
    }
    template<typename T> void swap_byte(T & data)
    {
        data = swap_byte_(data);
    }
    void print_tag(const char * tag)
    {
        std::cout << *tag++;
        std::cout << *tag++;
        std::cout << *tag++;
        std::cout << *tag++;
        std::cout << std::endl;
    }


    bool readfile(const char * name)
    {
        // ファイルを開く
        std::ifstream ifs(name);
        if (ifs.fail()) return false;
        // ファイルサイズを調べる
        auto begin = ifs.tellg();
        ifs.seekg(0, ifs.end);
        auto end = ifs.tellg();
        size_t size = static_cast<size_t>(end - begin);
        ifs.clear();
        ifs.seekg(0, ifs.beg);
        // バッファを確保して読み込む
        char * buf = new char[size + 1];
        buf[size] = 0;
        ifs.read(buf, size);
        // 読み込み処理
        auto result = read(buf, size);
        // バッファを破棄
        delete[] buf;
        // 結果を返す
        return result;
    }

    bool read(void * data, size_t size)
    {
        if (size < sizeof OTF_FILE_HEADER)
        {
            return false;
        }
        auto fileHeader = static_cast<OTF_FILE_HEADER *>(data);
        swap_byte(fileHeader->numTable);
        swap_byte(fileHeader->searchRange);
        swap_byte(fileHeader->entrySelector);
        swap_byte(fileHeader->rangeShift);
        print_tag(fileHeader->sfntVersion);

        auto tags = reinterpret_cast<OTF_DATA_HEADER *>(fileHeader + 1);

        for (uint16_t i = 0; i < fileHeader->numTable; ++i)
        {
            print_tag(tags[i].tag);
            swap_byte(tags[i].checkSum);
            swap_byte(tags[i].offset);
            swap_byte(tags[i].length);
        }

        return true;
    }
}

