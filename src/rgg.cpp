#include <iostream>
#include <random>
#include <algorithm>
#include "rgg/cli.h"
#include "rgg/iota.h"

int main(int argc, char** argv) try
{
    using NodeId = std::intmax_t;
    using OutDegree = std::intmax_t;

    auto cli = rgg::Cli{"rgg", argc, argv};

    std::random_device rd;
    std::default_random_engine nodesRg{rd()};
    std::default_random_engine outDegreeRg{rd()};

    using DegreeDist = std::uniform_int_distribution<OutDegree>;

    const auto nodesCnt = ez::utils::toSigned(cli.verticesCnt());
    const auto maxOutDegree = ez::utils::toSigned(cli.maxOutDegree());

    for (NodeId i = 0; i < nodesCnt; ++i) {
        std::cout << i;

        if (const auto restNodesCnt = nodesCnt - i - 1; restNodesCnt > 1) {
            auto outDegreeDist = DegreeDist{0, std::min(maxOutDegree, restNodesCnt)};
            const auto outDegree = outDegreeDist(outDegreeRg);

            std::cout << ' ';
            std::ranges::sample(
                rgg::details::Iota{i+1, i + restNodesCnt}, // TODO: try to adapt std::ranges::iota_view{i+1, nodesCnt-1}
                std::ostream_iterator<std::size_t>(std::cout, " "),
                outDegree,
                nodesRg
            );
        }

        std::cout << '\n';
    }

    return EXIT_SUCCESS;
}
catch(const std::exception& ex)
{
    std::cerr << "Exception is thrown with the message:\n" << ex.what() << '\n';
    return EXIT_FAILURE;
}
catch(...)
{
    std::cerr << "Unknown exception is thrown\n";
    return EXIT_FAILURE;
}
