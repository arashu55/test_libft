/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 00:58:17 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:01:57 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define SHADOW "\x1B[2m"
#define CYAN "\x1B[36m"
#define YEALLOW "\x1B[33m"
#define RESET "\x1B[0m"

void test_function_name()
{
   printf("《ft_strlen.c》");
   printf("\n");
}

const char *long_string = 
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

// 通常のテストケースにこの長い文字列を追加してテストします

void test_strlen()
{
   // int tests[];
   // int i;
   // int num;
   // tests = {-10, -1, 0, ' ', '@', 'A', 'M', 'Z', '[', '`', 'a', 'm', 'z', '{', '}', 127, 128, 150}
   // i = 0;
   const char *tests[] = {
    "",                         // 空文字列
    "Hello, world!",            // 通常の文字列
    "1234567890",               // 数字
    "     ",                    // スペースのみ
    "Hello\tworld\n",           // 制御文字を含む
    "\0hidden",                 // NUL文字が最初
    "This is a longer string to test the length function.", // 長い文字列
    "A",                        // 1文字だけ
    "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",  // 100文字を超える長い文字列
    "\xff\xfe\xfd",             // 非ASCII文字
    "\x01\x02\x03\x04\x05\x06", // 制御文字の列
    "\r\n\t\v\b\f",             // 改行やタブ、バックスペース、垂直タブなどの制御文字
    // NULL,                       // NULLポインタ

    // より特殊なケース
    "A\x00B",                   // NUL文字が途中に入った文字列 (strlen は NUL で止まる)
    "\0\0\0",                   // NUL 文字列のみ (長さ 0)
    "\x7F",                     // DEL (Delete) ASCII 127
    "\x80\x81\x82\x83\x84\x85", // 拡張ASCII (通常の ASCII 外の文字)
    
    // 長大な文字列
    "A string that is intentionally made long. A string that is intentionally made long. A string that is intentionally made long. A string that is intentionally made long.", // 長い文字列（繰り返しパターン）
    long_string, // 10万文字を超える長大文字列

    // Unicodeを含むケース（基本的にはstrlenはバイト単位で数えるが、ユニコードは複数バイトになる）
    "こんにちは",                  // マルチバイトの日本語文字列
    "👍🌟✨",                     // 絵文字（UTF-8で表現される）
    
    // 制御文字や特殊シーケンス
    "\033[31mHello\033[0m",       // ANSIエスケープシーケンスを含む文字列（色変更コード）
    "\n\t\v\f\r",                 // 改行、タブ、垂直タブ、フォームフィード、キャリッジリターン

    // // 負の文字コード（signed char で解釈されることがあるケース）
    // (const char *)-1,             // -1のポインタ（通常は無効）
    
    // // メモリ外アクセスを誘発するような危険なケース（通常はエラーハンドリングが必要）
    // (const char *)0xFFFFFFFF,     // メモリ外のアドレス
    // (const char *)0x00000000,     // 明示的にNULLポインタ
    // (const char *)0xDEADBEEF,     // 任意の無効なメモリアドレス
    };

   int num;
   int i = 0;
   num = sizeof(tests) / sizeof(tests[0]);

   while (i != num)
   {
      int ft;
      int honke;  
      ft = ft_strlen(tests[i]);
      honke = strlen(tests[i]);

      printf("【test%d】", i);
      if (ft == honke)
      {
         printf(GREEN "OK " RESET);
      }
      else
      {
         printf(RED "FAILED " RESET);
      }
      i++;
   }
   printf("\n");

   i = 0;

   while (i != num)
   {
      int ft;
      int honke;  
      ft = ft_strlen(tests[i]);
      honke = strlen(tests[i]);

      printf("【test%d】", i);
      if (ft == honke)
      {
         printf(SHADOW "libft is " RESET);
         printf(CYAN "%d" RESET,ft);
         printf(SHADOW "linux is " RESET);
         printf(CYAN "%d" RESET,honke);
      }
      else
      {
         printf(SHADOW "libft is " RESET);
         printf(CYAN "%d" RESET,ft);
         printf(SHADOW "linux is " RESET);
         printf(YEALLOW "%d" RESET,honke);
      }
      i++;
   }
   
   printf("\n");
   printf("\n");
}

int main() 
{
   test_function_name();
   test_strlen();
   return 0;
}
