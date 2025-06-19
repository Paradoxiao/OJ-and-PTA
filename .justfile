cpp_ path file:
  @g++ --std=c++23 {{path}}/{{file}}.cpp -o Play/out.exe
  @-just run
cpp_I path file:
  @g++ --std=c++23 {{path}}/{{file}}.cpp -o Play/out.exe
  @-just stdin {{path}} {{file}}
cpp_O path file:
  @g++ --std=c++23 {{path}}/{{file}}.cpp -o Play/out.exe
  @-just stdout {{path}} {{file}}
  @-just diff
cpp_IO path file:
  @g++ --std=c++23 {{path}}/{{file}}.cpp -o Play/out.exe
  @-just stdio {{path}} {{file}}
  @-just diff
c_ path file:
  @gcc --std=c23 {{path}}/{{file}}.c -o Play/out.exe
  @-just run
c_I path file:
  @gcc --std=c23 {{path}}/{{file}}.c -o Play/out.exe
  @-just stdin {{path}} {{file}}
c_O path file:
  @gcc --std=c23 {{path}}/{{file}}.c -o Play/out.exe
  @-just stdout {{path}} {{file}}
  @-just diff
c_IO path file:
  @gcc --std=c23 {{path}}/{{file}}.c -o Play/out.exe
  @-just stdio {{path}} {{file}}
  @-just diff
run:
  @command time -f "\nmemory: %M KiB\ntime  : %e s" Play/out.exe
stdin path file:
  @just splitio {{path}} {{file}}
  @command time -f "\nmemory: %M KiB\ntime  : %e s" Play/out.exe < Play/_input.txt
stdout path file:
  @just splitio {{path}} {{file}}
  @command time -f "\nmemory: %M KiB\ntime  : %e s" Play/out.exe > Play/output.txt
stdio path file:
  @just splitio {{path}} {{file}}
  @command time -f "\nmemory: %M KiB\ntime  : %e s" Play/out.exe < Play/_input.txt > Play/output.txt
splitio path file:
  @awk '/Sample Input/{flag=1;next}/Sample Output/{flag=0} flag' {{path}}/{{file}}.cpp > Play/_input.txt
  @awk '/Sample Output/{flag=1;next}/HINT/{flag=0} flag' {{path}}/{{file}}.cpp > Play/_output.txt
diff:
  @printf "\n\n" >> Play/output.txt
  @printf "\n\n" >> Play/_output.txt
  @sed -i ':a;$!{N;ba};s/\n*$//' Play/output.txt
  @sed -i ':a;$!{N;ba};s/\n*$//' Play/_output.txt
  @-diff Play/output.txt Play/_output.txt --minimal --color=always && echo -e "\e[32m---------\e[0m" || kitty --app-id __floating__ kitten diff Play/output.txt Play/_output.txt
code path file:
  @echo "" > Play/__io.txt
  @nvim Play/__io.txt
  @awk '/int main()/{flag=1}/한국어<   中文  فارسی  English  ไทย/{flag=0} flag' Play/__io.txt >> {{path}}/{{file}}.cpp
  @printf "/*\n\n" >> {{path}}/{{file}}.cpp
  @awk '/Description/{flag=1}/한국어<   中文  فارسی  English  ไทย/{flag=0} flag' Play/__io.txt >> {{path}}/{{file}}.cpp
  @printf "*/" >> {{path}}/{{file}}.cpp
