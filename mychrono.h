#include <chrono>
using namespace std;
class myChrono
{
private:
    static std::chrono::steady_clock::time_point s;
    static std::chrono::steady_clock::time_point e;

public:
    /**
     * Start measuring time
     */
    static void start() { s = std::chrono::steady_clock::now(); }

    /**
     * Stop measuring time
     */
    static void end() { e = std::chrono::steady_clock::now(); }

    /**
     * Get the elapsed time in milliseconds
     */
    static auto milliseconds() { return std::chrono::duration_cast<chrono::milliseconds>(e - s).count(); }

    /**
     * Get the elapsed time in nanoseconds
     */
    static auto nanoseconds() { return std::chrono::duration_cast<chrono::nanoseconds>(e - s).count(); }

    /**
     * Get the elapsed time in seconds
     */
    static auto seconds() { return std::chrono::duration_cast<chrono::seconds>(e - s).count(); }

    /**
     * Get the elapsed time in a specified duration
     * @param T duration type
     * @return elapsed time in T
     */
    template <typename T>
    static auto time() { return std::chrono::duration_cast<T>(e - s).count(); }
};
std::chrono::steady_clock::time_point myChrono::s;
std::chrono::steady_clock::time_point myChrono::e;