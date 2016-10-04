#if !defined(OTFREAD_OTFDATA_H)
#define OTFREAD_OTFDATA_H

#include <cstddef>
#include <cstdint>

/**
 * @brief otf ファイルヘッダ
 */
struct OTF_FILE_HEADER {
    char sfntVersion[4];
    uint16_t numTable;
    uint16_t searchRange;
    uint16_t entrySelector;
    uint16_t rangeShift;
};

struct OTF_DATA_HEADER {
    char tag[4];
    uint32_t checkSum;
    uint32_t offset;
    uint32_t length;
};

#endif // OTFREAD_OTFDATA_H

