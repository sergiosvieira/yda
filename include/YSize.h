/** \addgroup YDA
 * @{
 */

 #ifndef __YSIZE__
 #define __YSIZE__

//! Size structure
typedef struct YSize
{
    int width;
    int height;
    YSize(int a_width, int a_height): width(a_width),
                                      height(a_height)
    {}
} YSize;

 #endif /** __YSIZE__ **/
