/** \addgroup YDA
 * @{
 */

 #ifndef __YSIZE__
 #define __YSIZE__

//! Size structure
template <typename T>
struct YSize
{
    T width;
    T height;
    YSize(T a_width,
          T a_height):
          width(a_width),
          height(a_height)
    {}
};

 #endif /** __YSIZE__ **/
