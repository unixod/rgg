include_guard()

include(FetchContent)

###########################################
# Fetch dependencies
###########################################
FetchContent_Declare(ez-support
    GIT_REPOSITORY git@github.com:unixod/ez-support.git
    GIT_TAG 94042d476448b5e22b6ec295fec57651f80d0478
    GIT_SHALLOW On
)

FetchContent_Declare(ez-utils
    GIT_REPOSITORY git@github.com:unixod/ez-utils.git
    GIT_TAG 624561cb3943ec30b9933630daa2576e0067f0a4
    GIT_SHALLOW On
)


FetchContent_MakeAvailable(ez-support ez-utils)
