#ifndef GREETER_H
#define GREETER_H

#include <string>

/**
 * @brief A simple greeter class that produces greeting messages.
 *
 * The Greeter class demonstrates a basic hello-world application
 * with a testable public interface.
 */
class Greeter {
public:
    /**
     * @brief Constructs a Greeter with the given name.
     *
     * @param name The name to include in the greeting. Defaults to "World".
     */
    explicit Greeter(const std::string &name = "World") : name_(name) {}

    /**
     * @brief Returns a greeting string.
     *
     * @return A string in the format "Hello, <name>!".
     */
    std::string get_greeting() const { return "Hello, " + name_ + "!"; }

private:
    std::string name_;
};

#endif // GREETER_H
