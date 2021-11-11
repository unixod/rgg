include_guard()

include(FetchContent)

###########################################
# Fetch dependencies
###########################################
FetchContent_Declare(ez-support
    GIT_REPOSITORY git@github.com:unixod/ez-support.git
    GIT_TAG 962c720338b646d0cac4a7f2d15404b16ecc868a
    GIT_SHALLOW On
)

FetchContent_Declare(ez-utils
    GIT_REPOSITORY git@github.com:unixod/ez-utils.git
    GIT_TAG 599bd48e55a96ab8573323b6573c30c3ffbcd4c2
    GIT_SHALLOW On
)


FetchContent_MakeAvailable(ez-support ez-utils)
