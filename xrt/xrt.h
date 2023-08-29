#ifdef _WIN32
# ifdef XRT_SOURCE
#  define XRT_EXPORT __declspec(dllexport)
# else
#  define XRT_EXPORT __declspec(dllimport)
# endif
#endif

namespace xrt {

class xrt
{
public:
  XRT_EXPORT
  xrt();

  XRT_EXPORT
  ~xrt();

  XRT_EXPORT
  void
  run();
};

} // namespace xrt
