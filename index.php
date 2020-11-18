<?php

/*$res = exec("./cmd.sh");
echo $res;*/

if(isset($_GET["a"])&&isset($_GET["b"]))
{
    $n = $_GET["a"];
    $p = $_GET["b"];
/*    $n = "1";
    $p = "1";*/
    creat_file();
    write_file($n,$p);
    $res = todo();
    $bak = '';
    $jurdge1 = substr($res,-9);
    $jurdge2 = substr($res,-5);
    if(strlen($jurdge1 == "goodgame!"))
    {
        $bak = substr($res,0,4);
        echo "the right number is:  $bak";
        makefile1();
        delete_file();
        exec("./merge.sh");
    }
    elseif ($jurdge2 == "wrong")
    {
        echo "are you kidding me???";
        delete_file();
    }
    else
    {
        $bak =substr($res,-4);
        echo "i guess the number is $bak";
    }

}
else
{
    echo "i guess the number is 1234";
}

/*if (isset($_GET["c"]))
{
    exec("./merge.sh");
}*/
/*if (isset($_GET["d"])&&$_GET["d"] == 1)
{

}*/


function creat_file()
{
    $file = "in.txt";
    if (!file_exists($file))
    {
        touch($file);
    }

}
function write_file($x,$y)
{
    $txt = $x . ' ' . $y . "\n";
    file_put_contents("in.txt",$txt,FILE_APPEND);
}
function delete_file()
{
    exec("rm in.txt");
}

function todo()
{
    $res1 = exec("./cmd.sh");
    return $res1;
}
function makefile1()
{
    exec("./cmd2.sh");
}
