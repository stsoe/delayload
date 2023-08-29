#ifdef _WIN32
# ifdef VART_SOURCE
#  define VART_EXPORT __declspec(dllexport)
# else
#  define VART_EXPORT __declspec(dllimport)
# endif
#endif

namespace vart {

class vart
{
public:
  VART_EXPORT
  vart();

  VART_EXPORT
  ~vart();

  VART_EXPORT
  void
  run();
};

} // namespace vart
