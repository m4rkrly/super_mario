BUILD_TYPE="Ninja"
BUILD_FOLDER="build_linux_qt"
SOURCE_FOLDER="src"

mkdir -p "${BUILD_FOLDER}"
cd "${BUILD_FOLDER}"

export GAME_TYPE="Qt"

cmake -G "${BUILD_TYPE}" -DGAME_TYPE="${GAME_TYPE}" "../${SOURCE_FOLDER}"
cmake --build .

cd ..
