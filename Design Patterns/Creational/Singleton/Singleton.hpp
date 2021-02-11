#include <string>
#include <mutex>

class Singleton
{
    public:
        Singleton(const Singleton& rhs) = delete;
        Singleton(const Singleton&& rhs) = delete;
        Singleton& operator=(const Singleton& rhs) = delete;
        Singleton& operator=(const Singleton&& rhs) = delete;

        static Singleton* get_instance(const std::string& name);
        const std::string& get_name() const { return m_name;}

    protected:
        Singleton(const std::string& name) : m_name(name) {};

    private:
        static Singleton* singleton;
        static std::mutex mutex;
        std::string m_name;
};
