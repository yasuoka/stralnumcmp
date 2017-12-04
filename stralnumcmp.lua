function stralnumcmp(a, b)
    local a0, b0, an, bn, as, bs, c
    a0 = a
    b0 = b
    while (a:len() > 0 and b:len() > 0) do
	an = a:match('^%d+')
	bn = b:match('^%d+')
	as = not an and nil or a:match('^%D+')
	bs = not bn and nil or b:match('^%D+')
	if (an and bn) then
	    c = tonumber(an) - tonumber(bn)
	else
	    if (as and bs) then
		c = (as < bs) and -1 or ((as > bs) and 1 or 0)
	    else
		c = (as == nil) and -1 or 1
	    end
	end
	if (c ~= 0) then
	    return c
	end
	a = a:sub((an and an:len() or as:len()) + 1)
	b = b:sub((bn and bn:len() or bs:len()) + 1)
    end
    return (a0:len() - b0:len())
end
