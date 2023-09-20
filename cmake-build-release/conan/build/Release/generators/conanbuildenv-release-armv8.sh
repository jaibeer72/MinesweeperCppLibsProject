script_folder="/Users/jaibeerdugal/CLionProjects/MinesweeperProject/cmake-build-release/conan/build/Release/generators"
echo "echo Restoring environment" > "$script_folder/../../../build/Release/generators/deactivate_conanbuildenv-release-armv8.sh"
for v in 
do
    is_defined="true"
    value=$(printenv $v) || is_defined="" || true
    if [ -n "$value" ] || [ -n "$is_defined" ]
    then
        echo export "$v='$value'" >> "$script_folder/../../../build/Release/generators/deactivate_conanbuildenv-release-armv8.sh"
    else
        echo unset $v >> "$script_folder/../../../build/Release/generators/deactivate_conanbuildenv-release-armv8.sh"
    fi
done

