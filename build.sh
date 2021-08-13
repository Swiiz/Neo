echo "Running the docker buildenv image"
sudo docker run -d --name="neo-buildenv" --rm -it -v "$(pwd):/root/env" neo-buildenv
echo "Compiling the sources as x86_64"
sudo docker exec neo-buildenv make build-x86_64
echo "Stopping the docker container"
sudo docker stop neo-buildenv