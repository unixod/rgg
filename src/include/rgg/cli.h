#ifndef RGG_CLI_H
#define RGG_CLI_H

#include <string_view>
#include <ez/support/definitions.h>
#include <ez/utils/utils.h>

namespace rgg {
class Cli {
public:
    Cli(std::string_view appName, int argc, char** argv)
    {
        enum PositionalArgs {
            VerticesCnt = 1, MaxOutDegree,
            RequiredArgsCnt_ = MaxOutDegree + 1
        };

        if (argc != PositionalArgs::RequiredArgsCnt_) {
            throw std::runtime_error{
                ERR_MSG
                "Invalid number of arguments.\n"
                "Usage:\n"
                "    " + std::string{appName} + " <verices-count> <max-outdegree>\n"
            };
        }

        if (*ez::utils::cstrToUint(argv[VerticesCnt], verticesCnt_) != 0) {
            throw std::runtime_error{
                ERR_MSG
                "The first command line argument must be a positive integer value "
                "denoting number of vertices in the generated graph."
            };
        }

        if (*ez::utils::cstrToUint(argv[MaxOutDegree], maxOutDegree_) != 0) {
            throw std::runtime_error{
                ERR_MSG
                "The second command line argument must be a positive integer value "
                "denoting max outdegree of the vertices in the generated graph."
            };
        }
    }

    auto verticesCnt() const noexcept
    {
        return verticesCnt_;
    }

    auto maxOutDegree() const noexcept
    {
        return maxOutDegree_;
    }

private:
    std::size_t verticesCnt_ = 0;
    std::size_t maxOutDegree_ = 0;
};
}

#endif // RGG_CLI_H
