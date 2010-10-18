#!/bin/bash

library_name=animator
package_name=$library_name-$(cat version.txt)
build_dir=build/$library_name

echo "Packaging $package_name"

mkdir -p $build_dir
rm $build_dir/*

cp *.h $build_dir
cp *.cpp $build_dir
cp readme.txt $build_dir
cp license.txt $build_dir
cp version.txt $build_dir
cp changes.txt $build_dir

cd build
rm $package_name.zip
zip -r $package_name.zip $library_name
cd ..
 
