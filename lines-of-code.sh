#!/usr/bin/env bash

find "./src/" -type f -name "*.cpp" -o -name "*.h" | xargs wc -l
