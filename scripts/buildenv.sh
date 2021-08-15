echo "Building docker image for the build environment"
DIR=$(dirname $0)
sudo docker build "${DIR}/../buildenv" -t neo-buildenv