#!/usr/bin/bash

# Configure script, currently only support on unix like system

# Utils function
function promptSeparatorLine {
    lines="="
    if [[ $1 ]]; then
        lines=$1
    fi
    for ((i = 0; i < $(tput cols); i++)); do
        printf $lines
    done
    printf "\n"
}

function promptHelpOptions {
    echo "Usage: ./configure.sh (option)"
    promptSeparatorLine
    echo "Name: build"
    echo "Call: --build or -b"
    echo "Require: none"
    echo "Description: Build the app"
    promptSeparatorLine
    echo "Name: install"
    echo "Call: --install or -i"
    echo "Require: build"
    echo "Description: Install the app"
    promptSeparatorLine
    echo "Name: uninstall"
    echo "Call: --uninstall or -un"
    echo "Require: build"
    echo "Description: Uninstall the app"
    promptSeparatorLine
    echo "Name: clean"
    echo "Call: --clean or -c"
    echo "Require: build"
    echo "Description: Cleaning build dir"
    promptSeparatorLine
    echo "Name: build and install"
    echo "Call: --build-and-install or -bai"
    echo "Require: none"
    echo "Description: build and install the app"
    promptSeparatorLine
    echo "Name: test"
    echo "Call: --test or -t"
    echo "Require: build"
    echo "Description: testing the app"
    promptSeparatorLine
    echo "Name: build and test"
    echo "Call: --build-and-test or -bat"
    echo "Require: none"
    echo "Description: build and test the app"
    promptSeparatorLine
    echo "Name: clean all"
    echo "Call: --clean-all or -ca"
    echo "Require: build"
    echo "Description: Cleaning/remove build cache/dir"
}

# Configure function
function TestApp {
    if [[ ! -d build ]]; then
        echo "[LOG]: We can't test app, unless you have build cache"
        exit 1
    fi

    echo "[LOG]: Entering build dir..."
    sleep 1
    cd build
    echo "[LOG]: Testing app..."
    sleep 1
    ./bin/password-generator
    echo "[LOG]: Testing done..."
}

function BuildApp {
    if [[ ! -d build ]]; then
        echo "[LOG]: Creating build dir..."
        sleep 1
        mkdir build
    fi

    echo "[LOG]: Entering build dir..."
    sleep 1
    cd build
    echo "[LOG]: Executing cmake..."
    sleep 1
    cmake ..
    echo "[LOG]: Building app..."
    sleep 1
    make
    echo "[LOG]: Leaving build dir..."
    sleep 1
    cd ..
    echo "[LOG]: Building done"
}

function InstallApp {
    if [[ ! -d build ]]; then
        echo "[LOG]: We can't install the app, unless you have build cache"
        exit 1
    fi

    echo "[LOG]: Entering build dir..."
    sleep 1
    cd build
    echo "[LOG]: Installing app..."
    sleep 1
    make install
    echo "[LOG]: Leaving build dir..."
    sleep 1
    cd ..
    echo "[LOG]: Installation done"
}

function UninstallApp {
    if [[ ! -d build ]]; then
        echo "[LOG]: We can't uninstall app, unless you have build cache"
        exit 1
    fi

    echo "[LOG]: Entering build dir..."
    sleep 1
    cd build
    echo "[LOG]: Uninstalling the app..."
    sleep 1
    make uninstall
    echo "[LOG]: Leaving build dir..."
    sleep 1
    cd ..
    echo "[LOG]: Uninstallation done"
}

function CleanBuildDir {
    if [[ ! -d build ]]; then
        echo "[LOG]: We can't clean build dir, unless you have build cache"
        exit 1
    fi

    echo "[LOG]: Entering build dir..."
    sleep 1
    cd build
    echo "[LOG]: Cleaning build..."
    sleep 1
    make clean
    echo "[LOG]: Leaving build dir..."
    sleep 1
    cd ..
    echo "[LOG]: Cleaning done"
}

function CleanAll {
    if [[ ! -d build ]]; then
        echo "[LOG]: We can't removing build dir, unless you have build cache"
        exit 1
    fi

    echo "[LOG]: Removing build dir..."
    sleep 1
    rm -r build
    echo "[LOG]: Removing build dir done."
}

# If argument doesn't exist
if [[ ! $1 ]]; then
    echo "[LOG]: Please enter one argument, see ./configure.sh --help to see list options"
    exit 1
fi

# Arguments handler
if [[ $1 == "--build" || $1 == "-b" ]]; then
    BuildApp
elif [[ $1 == "--install" || $1 == "-i" ]]; then
    InstallApp
elif [[ $1 == "--uninstall" || $1 == "-un" ]]; then
    UninstallApp
elif [[ $1 == "--clean" || $1 == "-c" ]]; then
    CleanBuildDir
elif [[ $1 == "--build-and-install" || $1 == "-bai" ]]; then
    BuildApp
    InstallApp
elif [[ $1 == "--build-and-install" || $1 == "-bat" ]]; then
    BuildApp
    TestApp
elif [[ $1 == "--clean-all" || $1 == "-ca" ]]; then
    CleanAll
elif [[ $1 == "--testing" || $1 == "-t" ]]; then
    TestApp
elif [[ $1 == "--help" || $1 == "-h" ]]; then
    promptHelpOptions
else
    echo "[LOG]: Sorry option $1 doesn't exist"
    echo "See ./configure.sh --help to get list options"
fi
