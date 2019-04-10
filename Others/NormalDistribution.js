// 正規分布に従う乱数
// 一様分布からBox–Muller変換して生成
const normalDistribution = (mean, sd) => {
    const x = Math.random();
    const y = Math.random();

    const z1 = Math.sqrt(-2 * Math.log(x)) * Math.cos(2 * Math.PI * y);
    // const z2 = Math.sqrt(-2 * Math.log(x)) * Math.sin(2 * Math.PI * y);
    return sd * z1 + mean;
}