<?php
function download($filename){
//检测是否设置文件名和文件是否存在
    if ((isset($filename))&&(file_exists($filename))){
        header("Content-length: ".filesize($filename));
        header('Content-Type: application/octet-stream');
        header('Content-Disposition: attachment; filename="' . $filename . '"');
        readfile("$filename");
    } else {
        echo "文件不存在!";
    }
}
download('./all.txt');
header("Refresh:3;url=guess.html");
?>
