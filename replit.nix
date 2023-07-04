{ pkgs }: {
	deps = [
		pkgs.fim
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}