function stralnumcmp(a, b)
    local a0, b0, an, bn, as, bs, c
    a0 = a
    b0 = b
    while (a:len() > 0 and b:len() > 0) do
	an = a:match('^%d+')
	bn = b:match('^%d+')
	as = an or a:match('^%D+')
	bs = bn or b:match('^%D+')

	if (an and bn) then
	    c = tonumber(an) - tonumber(bn)
	else
	    c = (as < bs) and -1 or ((as > bs) and 1 or 0)
	end
	if (c ~= 0) then
	    return c
	end
	a = a:sub((an and an:len() or as:len()) + 1)
	b = b:sub((bn and bn:len() or bs:len()) + 1)
    end
    return (a0:len() - b0:len())
end
