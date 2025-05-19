cpp_ path file:
  @g++ --std=c++23 {{path}}/{{file}}.cpp -o Play/out.exe
  @Play/out.exe
cpp_I path file:
  @g++ --std=c++23 {{path}}/{{file}}.cpp -o Play/out.exe
  @cat Play/_input.txt | Play/out.exe
cpp_O path file:
  @g++ --std=c++23 {{path}}/{{file}}.cpp -o Play/out.exe
  @Play/out.exe > Play/_output.txt
cpp_IO path file:
  @g++ --std=c++23 {{path}}/{{file}}.cpp -o Play/out.exe
  @cat Play/_input.txt | Play/out.exe > Play/_output.txt

c_ path file:
  @gcc --std=c23 {{path}}/{{file}}.cpp -o Play/out.exe
  @Play/out.exe
c_I path file:
  @gcc --std=c23 {{path}}/{{file}}.cpp -o Play/out.exe
  @cat Play/_input.txt | Play/out.exe
c_O path file:
  @gcc --std=c23 {{path}}/{{file}}.cpp -o Play/out.exe
  @Play/out.exe > Play/_output.txt
c_IO path file:
  @gcc --std=c23 {{path}}/{{file}}.cpp -o Play/out.exe
  @cat Play/_input.txt | Play/out.exe > Play/_output.txt
