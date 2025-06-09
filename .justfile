cpp_ path file:
  @g++ --std=c++23 {{path}}/{{file}}.cpp -o Play/out.exe
  @command time -f "\nmemory: %M KiB\ntime  : %e s" Play/out.exe
cpp_I path file:
  @g++ --std=c++23 {{path}}/{{file}}.cpp -o Play/out.exe
  @command time -f "\nmemory: %M KiB\ntime  : %e s" Play/out.exe < Play/_input.txt
cpp_O path file:
  @g++ --std=c++23 {{path}}/{{file}}.cpp -o Play/out.exe
  @command time -f "\nmemory: %M KiB\ntime  : %e s" Play/out.exe > Play/_output.txt
  @printf "\n\n" >> Play/_output.txt
  @printf "\n\n" >> Play/__io.txt
  @sed -i ':a;$!{N;ba};s/\n*$//' Play/_output.txt
  @sed -i ':a;$!{N;ba};s/\n*$//' Play/__io.txt
  @-diff Play/_output.txt Play/__io.txt --minimal --color=always && echo -e "\e[32m---------\e[0m" || kitty kitten diff Play/_output.txt Play/__io.txt
cpp_IO path file:
  @g++ --std=c++23 {{path}}/{{file}}.cpp -o Play/out.exe
  @command time -f "\nmemory: %M KiB\ntime  : %e s" Play/out.exe < Play/_input.txt > Play/_output.txt
  @printf "\n\n" >> Play/_output.txt
  @printf "\n\n" >> Play/__io.txt
  @sed -i ':a;$!{N;ba};s/\n*$//' Play/_output.txt
  @sed -i ':a;$!{N;ba};s/\n*$//' Play/__io.txt
  @-diff Play/_output.txt Play/__io.txt --minimal --color=always && echo -e "\e[32m---------\e[0m" || kitty kitten diff Play/_output.txt Play/__io.txt
c_ path file:
  @gcc --std=c23 {{path}}/{{file}}.c -o Play/out.exe
  @command time -f "\nmemory: %M KiB\ntime  : %e s" Play/out.exe
c_I path file:
  @gcc --std=c23 {{path}}/{{file}}.c -o Play/out.exe
  @command time -f "\nmemory: %M KiB\ntime  : %e s" cat Play/_input.txt | Play/out.exe
c_O path file:
  @gcc --std=c23 {{path}}/{{file}}.c -o Play/out.exe
  @command time -f "\nmemory: %M KiB\ntime  : %e s" Play/out.exe > Play/_output.txt
  @printf "\n\n" >> Play/_output.txt
  @printf "\n\n" >> Play/__io.txt
  @sed -i ':a;$!{N;ba};s/\n*$//' Play/_output.txt
  @sed -i ':a;$!{N;ba};s/\n*$//' Play/__io.txt
  @-diff Play/_output.txt Play/__io.txt --minimal --color=always && echo -e "\e[32m---------\e[0m" || kitty kitten diff Play/_output.txt Play/__io.txt
c_IO path file:
  @gcc --std=c23 {{path}}/{{file}}.c -o Play/out.exe
  @command time -f "\nmemory: %M KiB\ntime  : %e s" cat Play/_input.txt | Play/out.exe > Play/_output.txt
  @printf "\n\n" >> Play/_output.txt
  @printf "\n\n" >> Play/__io.txt
  @sed -i ':a;$!{N;ba};s/\n*$//' Play/_output.txt
  @sed -i ':a;$!{N;ba};s/\n*$//' Play/__io.txt
  @-diff Play/_output.txt Play/__io.txt --minimal --color=always && echo -e "\e[32m---------\e[0m" || kitty kitten diff Play/_output.txt Play/__io.txt
