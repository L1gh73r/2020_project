#!/usr/bin/expect --
set f [open in.txt]
spawn ./b.out
while {1} {
    set line [gets $f]
    expect "emmmmm...   " {send "$line\r"};
    if {[eof $f]} {
        close $f
        break
    }
    #puts "Read line: $line"
    #expect "emmmmm...   " {send "$line\r"};
}
