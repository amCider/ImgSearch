# Shift+F10
# python　画像部分一致 https://qiita.com/anzanshi/items/507729a3c474fa3151fc
# python 文字列から文字を取り出す https://note.nkmk.me/python-str-extract/
# 課題:サイズがでかい、融通がきかない、選択肢がない(改善できない)、終了時に完了のポップアップを出す
import cv2
import glob
import os
import csv
import re


def push_stamp(num):
    if 0.80 < num:
        return 1
    else:
        return 0


files = glob.glob("./data/img/*")  # 検索画像保管フォルダパスを指定
template = cv2.imread('./data/temp.png')
wrcsv = []

for fname in files:
    # 検索対象画像の読み込み
    image = cv2.imread(fname)
    # 画像マッチング処理
    result = cv2.matchTemplate(image, template, cv2.TM_CCORR_NORMED)
    # 最も類似度が高い位置を取得する。
    minVal, maxVal, minLoc, maxLoc = cv2.minMaxLoc(result)
    # 類似度から、判定結果を求める（上で設定した式を使用）
    Judg = push_stamp(maxVal)
    # ファイルパスから、ファイル名と拡張子を取得
    filename, ext = os.path.splitext(os.path.basename(fname))
    # CSVに書き込み
    if Judg == 1:
        # line_num = (re.findall('_(.*)', filename))[0]
        line_num = re.search(r'_(.*)', filename)
        # print(line_num.group(1))
        with open("./data/aaa.txt", "r") as f:
            txt_str = f.readlines()[int(line_num.group(1))-1]
            txt_str = txt_str.strip()
        wrcsv.append([filename, txt_str])


with open('./data/output.csv', "w") as f:  # 文字コードをShift_JISに指定
    writer2 = csv.writer(f, lineterminator="\n")  # writerオブジェクトの作成 改行記号で行を区切る
    writer2.writerows(wrcsv)  # csvファイルに書き込み
