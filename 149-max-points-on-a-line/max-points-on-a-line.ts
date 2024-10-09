function maxPoints(points: number[][]): number {
    let n = points.length;
    let ans:number = 0;
    for(let i = 0; i < n; i++){
        let map: Map<number, number> = new Map();
        for(let j = 0; j < n; j++){
            if(i == j) continue;
            let dy = points[j][1] - points[i][1];
            let dx = points[j][0] - points[i][0];
            let val = Math.atan2(dy, dx);
            map.set(val, (map.get(val) || 0) + 1);
        }
        map.forEach((value, key) => {
            ans = Math.max(ans, value);
        });
    }
    return ans + 1;
};