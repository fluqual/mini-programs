use std::io;

fn matrix_multiplicate(x: Vec<Vec<i32>>, y: Vec<Vec<i32>>) {}
fn main() {
    let mut input: String = "".to_string();
    let mut rowsx: i32;
    let mut columnsx: i32;
    let mut rowsy: i32;
    let mut columnsy: i32;
    println!("Введите число строк первой матрицы: ");
    io::stdin().read_line(&mut input).expect("Ошибка чтения вывода");
    rowsx = input.parse::<i32>().unwrap();
    println!("Введите число столбцов первой матрицы: ");
    io::stdin().read_line(&mut input).expect("Ошибка чтения вывода");
    columnsx = input.parse::<i32>().unwrap();
    println!("Введите число строк второй матрицы: ");
    io::stdin().read_line(&mut input).expect("Ошибка чтения вывода");
    rowsy = input.parse::<i32>().unwrap();
    println!("Введите число столбцов первой матрицы: ");
    io::stdin().read_line(&mut input).expect("Ошибка чтения вывода");
    columnsy = input.parse::<i32>().unwrap();
}
