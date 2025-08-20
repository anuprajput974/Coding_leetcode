# Write your MySQL query statement below
SELECT
 pt.product_name,
 sb.year,
 sb.price
FROM
 sales  as sb
left join product as pt
on
 sb.product_id=pt.product_id;